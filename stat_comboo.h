#ifndef STAT_COMBOO_H
#define STAT_COMBOO_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat_comboo;
}

class stat_comboo : public QDialog
{
    Q_OBJECT

public:
    explicit stat_comboo(QWidget *parent = nullptr);
    ~stat_comboo();

    QChartView *chartView ;
    void choix_bar1();
    void choix_pie();

private:
    Ui::stat_comboo *ui;
};

#endif // STAT_COMBO_H
