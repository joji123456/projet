#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "garderie.h"
#include "enseignants.h"
#include <QRegularExpression>
#include <QLineEdit>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_12->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->lineEdit_13->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->lineEdit_14->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->lineEdit_15->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z]*")));
    ui->lineEdit_5->setValidator(new QRegExpValidator(QRegExp("[0-9]{3}$")));
    ui->comboBox_4->setModel(Etmp.setid());
    ui->comboBox_9->setModel(etmp.setide());

   // ui->lineEdit_4->setModel(Etmp.setid());
}

MainWindow::~MainWindow()
{
    delete ui;
}









void MainWindow::on_pushButton_clicked()

{
    int x=0;
            int ID_EL=ui->lineEdit->text().toInt();
            QRegularExpression regex1("^[0-9]{8}$");// Expression régulière pour 8 chiffres consécutifs
            QString NOM=ui->lineEdit_2->text();
            QRegularExpression regex("^[a-zA-Z]+$"); // Expression régulière pour des lettres uniquement

            QString PRENOM=ui->lineEdit_3->text();
            QRegularExpression regex2("^[a-zA-Z]+$"); // Expression régulière pour des lettres uniquement
            QString PHOTO=ui->lineEdit_10->text();
            QString CLASSE=ui->comboBox->currentText();

            int AGE=ui->lineEdit_5->text().toInt();
            if (regex.match(NOM).hasMatch() && regex2.match(PRENOM).hasMatch()&& x==0) {
                // Le nom est valide, on peut l'utiliser
                // ... (code pour traiter le nom valide)


                x=1;





            } else {
                // Le nom est invalide
              QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("ajout non effectué. \n" " click cancel to exit") );
               QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres.");
                QMessageBox::warning(this, "Erreur", "Le ID_EL ne doit contenir que 8 chiffres.");
            }
            garderie g(ID_EL , NOM , PRENOM, CLASSE, AGE,PHOTO);
             bool test=g.ajouter();
            if(test && x==1){
                //actualiser
                // ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
            ui->tableView->setModel(Etmp.afficher());
            ui->comboBox_4->setModel(Etmp.setid());
           //  ui->comboBox_5->setModel(Etmp.setid());
               QMessageBox::information(nullptr, QObject::tr("cancel"),QObject::tr("Ajout effectué\n" "click cancel to exit."), QMessageBox::Cancel);

            }else QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("ajout non effectué. \n" " click cancel to exit") );

}

void MainWindow::on_pushButton_2_clicked(){

    ui->tableView->setModel(Etmp.afficher());


}




void MainWindow::on_pushButton_3_clicked()
{
    garderie g(ui->comboBox_4->currentText().toInt(),ui->lineEdit_6->text(),ui->lineEdit_7->text(),ui->comboBox_2->currentText(),ui->lineEdit_8->text().toInt(),ui->lineEdit_11->text());

    bool test=g.modifier();




    if(test){
        //actualiser
    ui->tableView->setModel(Etmp.afficher());
       QMessageBox::information(nullptr, QObject::tr("cancel"),QObject::tr("modification effectué\n" "click cancel to exit."), QMessageBox::Cancel);

    }

        else QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("modification non effectué. \n" " click cancel to exit") );
}






void MainWindow::on_comboBox_4_activated(int index)
{
    QSqlQuery query;

           query.prepare("select * from  ELEVE  where ID_EL=:ID_EL ");

           query.bindValue(":ID_EL",ui->comboBox_4->currentText().toInt());

           if(query.exec())

               while(query.next())

       {


           ui->lineEdit_6->setText(query.value(1).toString()) ;
           ui->lineEdit_7->setText(query.value(2).toString()) ;
           ui->lineEdit_9->setText(query.value(3).toString()) ;
           ui->lineEdit_8->setText(query.value(4).toString()) ;
           ui->lineEdit_11->setText(query.value(5).toString()) ;




}}

void MainWindow::on_pushButton_4_clicked()
{
     ui->comboBox_4->setModel(Etmp.setid());
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();

            ui->comboBox->setCurrentIndex(0);
            ui->lineEdit_5->clear();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();

    ui->comboBox_2->setCurrentIndex(0);
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();

}

void MainWindow::on_pushButton_8_clicked()
{
   ui->comboBox_3->setModel(Etmp.setid());
}

void MainWindow::on_pushButton_7_clicked()
{
    int NUMERO=ui->comboBox_3->currentText().toInt();
        bool test=Etmp.supprimer(NUMERO);

        if(test){
            //actualiser
    ui->tableView->setModel(Etmp.afficher());
    ui->comboBox_4->setModel(Etmp.setid());
    ui->comboBox_3->setModel(Etmp.setid());


            QMessageBox::information(nullptr, QObject::tr("supp"),QObject::tr("suppression effectué\n" "click cancel to exit."), QMessageBox::Cancel);

        }

            else QMessageBox::critical(nullptr ,QObject::tr("not supp"),QObject::tr("suppression non effectué. \n" " click cancel to exit") );
}

void MainWindow::on_pushButton_9_clicked()
{
    garderie Etmp;
        ui->tableView->setModel(Etmp.afficher5(ui->comboBox_5->currentText()));
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    garderie Etmp;
            ui->tableView->setModel(Etmp.afficher4(ui->comboBox_6->currentText(),ui->lineEdit_4->text()));
}

void MainWindow::on_pushButton_10_clicked()
{
    s=new stat_combo();

     s->setWindowTitle("statistique ComboBox");
     s->choix_pie();
     s->show();
}

void MainWindow::on_pushButton_11_clicked()
{
    QPdfWriter pdf("C:/Users/21697/Desktop/PORJET QT/garderie_scolaire/PDF/eleve.pdf");
       QPainter painter(&pdf);

       // set background color
       painter.setBackground(QBrush(QColor("#464646")));
       painter.eraseRect(0, 0, pdf.width(), pdf.height());

       int v = 4000;
       painter.setPen(QPen(QColor("#ffc34a")));
       painter.setFont(QFont("Arial", 30, QFont::Bold));
       painter.drawText(2000, 1400, "LISTE DES ELEVES");

       painter.setPen(QPen(QColor("#ffc34a")));
       painter.setFont(QFont("Arial", 15));
       painter.drawRect(100, 100, 9400, 2500);
       painter.drawRect(100, 3000, 9400, 500);


       painter.setFont(QFont("Arial", 10, QFont::Bold));
       painter.setPen(QPen(QColor("#ffc34a")));
       painter.drawText(500, 3300, "ID ");
       painter.drawText(1000, 3300, "NOM ");
       painter.drawText(2000, 3300, "PRENOM");
       painter.drawText(5000, 3300, "CLASSE");
       painter.drawText(6000, 3300, "AGE");


       QSqlQuery query;
       query.prepare("select * from ELEVE");
       query.exec();
       while (query.next())
       {
           painter.setFont(QFont("Arial", 10));
           painter.setPen(QPen(QColor("#ffc34a")));
           painter.drawText(500, v, query.value(0).toString());
           painter.drawText(1000, v, query.value(1).toString());
           painter.drawText(2000, v, query.value(2).toString());
           painter.drawText(5000, v, query.value(3).toString());
           painter.drawText(6000, v, query.value(4).toString());


           // Draw horizontal line after writing text for each row
           painter.setPen(QPen(QColor("#ffc34a")));
           painter.drawLine(100, v+50, 9500, v+50);

           v = v + 350;
       }

       // Move this line to the end of the while loop
       painter.setPen(QPen(QColor("#ffc34a")));
       painter.drawRect(100, 3000, 9400, 9000);

       QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
           QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_12_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
        ui->lineEdit_10->setText(filename);
}

void MainWindow::on_pushButton_13_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");
            ui->lineEdit_11->setText(filename);
}

void MainWindow::on_tableView_pressed(const QModelIndex &index)
{
    QString imagePath = index.data().toString(); // Chemin de l'image

        QPixmap pixmap(imagePath);

            // Afficher l'image dans un QLabel (assumant que vous avez un QLabel nommé "label_image")
            ui->label_14->setPixmap(pixmap.scaled(ui->label_14->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::on_pushButton_14_clicked()
{
    int x=0;
            int ID_EN=ui->lineEdit_12->text().toInt();
            QRegularExpression regex1("^[0-9]{8}$");// Expression régulière pour 8 chiffres consécutifs
            QString NOM_EN=ui->lineEdit_13->text();
            QRegularExpression regex("^[a-zA-Z]+$"); // Expression régulière pour des lettres uniquement

            QString PRENOM_EN=ui->lineEdit_14->text();
            QRegularExpression regex2("^[a-zA-Z]+$"); // Expression régulière pour des lettres uniquement
           int NB_HEURS=ui->comboBox_7->currentText().toInt();
            QString SPECIALITE=ui->lineEdit_15->text();
            QRegularExpression regex3("^[a-zA-Z]+$"); // Expression régulière pour des lettres uniquement



            if (regex.match(NOM_EN).hasMatch() && regex2.match(PRENOM_EN).hasMatch()&&regex3.match(SPECIALITE).hasMatch()&& x==0) {
                // Le nom est valide, on peut l'utiliser
                // ... (code pour traiter le nom valide)


                x=1;





            } else {
                // Le nom est invalide
              QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("ajout non effectué. \n" " click cancel to exit") );
               QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres.");
                QMessageBox::warning(this, "Erreur", "Le ID_EL ne doit contenir que 8 chiffres.");
            }
           ENSEIGNANTS E(ID_EN , NOM_EN , PRENOM_EN, NB_HEURS, SPECIALITE);
             bool test=E.ajoutere();
            if(test && x==1){
                //actualiser
                // ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
            ui->tableView_2->setModel(etmp.affichere());
            ui->comboBox_9->setModel(etmp.setide());
             ui->comboBox_11->setModel(etmp.setide());
               QMessageBox::information(nullptr, QObject::tr("cancel"),QObject::tr("Ajout effectué\n" "click cancel to exit."), QMessageBox::Cancel);

            }else QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("ajout non effectué. \n" " click cancel to exit") );

}

void MainWindow::on_pushButton_15_clicked()
{
    ui->lineEdit_12->clear();
            ui->lineEdit_13->clear();
            ui->lineEdit_14->clear();

            ui->comboBox_7->setCurrentIndex(0);
            ui->lineEdit_15->clear();
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->tableView_2->setModel(etmp.affichere());
}

void MainWindow::on_pushButton_17_clicked()
{
    ENSEIGNANTS E(ui->comboBox_9->currentText().toInt(),ui->lineEdit_16->text(),ui->lineEdit_17->text(),ui->comboBox_10->currentText().toInt(),ui->lineEdit_18->text());

    bool test=E.modifiere();




    if(test){
        //actualiser
    ui->tableView->setModel(etmp.affichere());
       QMessageBox::information(nullptr, QObject::tr("cancel"),QObject::tr("modification effectué\n" "click cancel to exit."), QMessageBox::Cancel);

    }

        else QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("modification non effectué. \n" " click cancel to exit") );
}





void MainWindow::on_pushButton_18_clicked()
{
    ui->comboBox_9->setModel(etmp.setide());
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();

    ui->comboBox_10->setCurrentIndex(0);
    ui->lineEdit_18->clear();
    ui->lineEdit_19->clear();
}

void MainWindow::on_comboBox_9_activated(int index)
{
    QSqlQuery query;

           query.prepare("select * from  ENSEIGNANT  where ID_EN=:ID_EN ");

           query.bindValue(":ID_EN",ui->comboBox_9->currentText().toInt());

           if(query.exec())

               while(query.next())

       {


           ui->lineEdit_16->setText(query.value(1).toString()) ;
           ui->lineEdit_17->setText(query.value(2).toString()) ;
           ui->lineEdit_19->setText(query.value(3).toString()) ;
           ui->lineEdit_18->setText(query.value(4).toString()) ;





}
}

void MainWindow::on_pushButton_20_clicked()
{
    int NUMERO=ui->comboBox_8->currentText().toInt();
        bool test=etmp.supprimere(NUMERO);

        if(test){
            //actualiser
    ui->tableView->setModel(etmp.affichere());
    ui->comboBox_9->setModel(etmp.setide());
    ui->comboBox_8->setModel(etmp.setide());


            QMessageBox::information(nullptr, QObject::tr("supp"),QObject::tr("suppression effectué\n" "click cancel to exit."), QMessageBox::Cancel);
}}

void MainWindow::on_pushButton_21_clicked()
{
    ui->comboBox_8->setModel(etmp.setide());
}

void MainWindow::on_pushButton_23_clicked()
{
    ss=new stat_comboo();

     ss->setWindowTitle("statistique ComboBox");
     ss->choix_pie();
     ss->show();
}

void MainWindow::on_pushButton_22_clicked()
{
    ENSEIGNANTS etmp;
        ui->tableView_2->setModel(etmp.affichere5(ui->comboBox_11->currentText()));
}



void MainWindow::on_lineEdit_20_textChanged(const QString &arg1)
{
    ENSEIGNANTS etmp;
            ui->tableView_2->setModel(etmp.affichere4(ui->comboBox_12->currentText(),ui->lineEdit_20->text()));
}
