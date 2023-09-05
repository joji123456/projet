#include "stat_combo.h"
#include "ui_stat_combo.h"

stat_combo::stat_combo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat_combo)
{
    ui->setupUi(this);
}

stat_combo::~stat_combo()
{
    delete ui;
}



    void stat_combo::choix_pie()
    {
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0,c3=0;

    q1.prepare("SELECT * FROM ELEVE");
    q1.exec();

    q2.prepare("SELECT * FROM ELEVE WHERE CLASSE='S1'");
    q2.exec();

    q3.prepare("SELECT * FROM ELEVE WHERE CLASSE='S2'");
    q3.exec();

    q4.prepare("SELECT * FROM ELEVE WHERE CLASSE='S3' ");
    q4.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}
    while (q4.next()){c3++;}

    c1=c1/tot;
    c2=c2/tot;
    c3=c3/tot;

    // Define slices and percentage of whole they take up
    QPieSeries *series = new QPieSeries();
    series->append("s1",c1);
    series->append("s2",c2);
    series->append("s3",c3);




    // Create the chart widget
    QChart *chart = new QChart();

    // Add data to chart with title and show legend
    chart->addSeries(series);
    chart->legend()->show();


    // Used to display the chart
    chartView = new QChartView(chart,ui->label_stat);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(400,400);
    series->setLabelsVisible();
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);

       // for(auto slice : series->slices())


        //series->append("under 100",c1);
        //series->append("over 100",c2);

    chartView->show();
    }
