#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QStandardItemModel"
#include "garderie.h"
#include "enseignants.h"
#include "stat_combo.h"
#include "stat_comboo.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
   // void on_comboBox_3_activated(int index);
    void on_comboBox_4_activated(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_lineEdit_4_textChanged(const QString &arg1);

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_tableView_pressed(const QModelIndex &index);

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_comboBox_10_activated(const QString &arg1);

    void on_comboBox_9_activated(const QString &arg1);

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_comboBox_9_activated(int index);

    void on_pushButton_20_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_pushButton_21_clicked();

    void on_pushButton_23_clicked();

    void on_comboBox_5_activated(const QString &arg1);

    void on_pushButton_22_clicked();

    void on_pushButton_24_clicked();

    void on_comboBox_6_activated(const QString &arg1);

    void on_lineEdit_20_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QStandardItemModel *modele;
    garderie Etmp;
    ENSEIGNANTS etmp;
    stat_combo *s;
    stat_comboo *ss;
};
#endif // MAINWINDOW_H
