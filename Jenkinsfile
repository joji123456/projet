pipeline {
    agent any

    environment {
        REPORT_DIR = "${WORKSPACE}/reports"
    }

    stages {

        stage('Prepare Workspace') {
            steps {
                sh '''
                echo "[INFO] Creating reports directory..."
                mkdir -p "$REPORT_DIR"
                '''
            }
        }

       stage('Checkout SCM') {
            steps {
                checkout scm
            }
        }

        stage('Vulnerability Scan - Trivy') {
            steps {
                sh '''
                if command -v trivy >/dev/null 2>&1; then
                  echo "[INFO] Running Trivy filesystem scan..."
                  trivy fs --no-progress --format json -o "$REPORT_DIR/trivy-fs-report.json" .

                  echo "[INFO] Running Trivy image scan on devsecops-app..."
                  trivy image --no-progress --format json -o "$REPORT_DIR/trivy-image-report.json" devsecops-app || true
                else
                  echo "[WARN] Trivy not installed. Skipping scan."
                fi
                '''
            }
        }

        stage('DAST - ZAP Scan') {
            steps {
                sh '''
                if ! command -v zap-cli >/dev/null 2>&1; then
                  echo "[WARN] zap-cli is not installed. Skipping ZAP scan."
                  exit 0
                fi

                echo "[INFO] Restarting ZAP container..."
                docker stop zap || true
                docker rm zap || true

                docker run -u root -d \
                  --name zap \
                  -p 8090:8090 \
                  ghcr.io/zaproxy/zaproxy:stable \
                  zap.sh -daemon \
                    -host 0.0.0.0 \
                    -port 8090 \
                    -config api.key=12345 \
                    -config api.addrs.addr.name=.* \
                    -config api.addrs.addr.regex=true

                echo "[INFO] Waiting for ZAP..."
                sleep 40

                echo "[INFO] Running ZAP quick scan..."
                zap-cli --zap-url http://localhost --port 8090 --api-key 12345 quick-scan http://localhost:3000 || true

                echo "[INFO] Exporting ZAP report..."
                mkdir -p "$REPORT_DIR"
                zap-cli --zap-url http://localhost --port 8090 --api-key 12345 report \
                  -o "$REPORT_DIR/zap-report.html" -f html || true

                docker stop zap || true
                docker rm zap || true
                '''
            }
        }

        stage('SonarQube Analysis') {
            steps {
                sh '''
                if command -v sonar-scanner >/dev/null 2>&1; then
                  echo "[INFO] Running SonarQube analysis..."
                  sonar-scanner \
                    -Dsonar.projectKey=devsecops-app \
                    -Dsonar.sources=. \
                    -Dsonar.host.url=http://localhost:9000 \
                    -Dsonar.login=VOTRE_TOKEN_SONAR_ICI || true
                else
                  echo "[WARN] sonar-scanner not installed. Skipping analysis."
                fi
                '''
            }
        }

        /************************************************************
         *  BUILD DOCKER IMAGE → déplacé JUSTE AVANT DEPLOY (demandé)
         ************************************************************/
        stage('Build Docker Image') {
            steps {
                sh '''
                echo "[INFO] Building Docker image devsecops-app..."
                docker build -t devsecops-app .
                '''
            }
        }

        /*******************
         *   DEPLOY STAGE  *
         *******************/
        stage('Deploy') {
            steps {
                sh '''
                echo "[INFO] Deploying devsecops-app container on port 3000..."
                docker stop devsecops-app || true
                docker rm devsecops-app || true
                docker run -d --name devsecops-app -p 3000:3000 devsecops-app || true
                '''
            }
        }
    }

    post {
        always {
            echo "Pipeline terminé. Les rapports se trouvent dans ${REPORT_DIR}"
            archiveArtifacts artifacts: 'reports/**/*.*', fingerprint: true, allowEmptyArchive: true
        }
    }
}
