#ifndef ENSEIGNANTS_H
#define ENSEIGNANTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class ENSEIGNANTS
{
public:

    QSqlQueryModel * setide();

    bool ajoutere();

    bool supprimere(int );
    bool modifiere();
    bool modifierte();
    QSqlQueryModel * affichere() ;
    QSqlQueryModel * affichere5(QString a);
    QSqlQueryModel * affichere4(QString a,QString b);
    ENSEIGNANTS();
    ENSEIGNANTS(int ,QString ,QString ,int,QString);


private:
    int ID_EN;
    QString NOM_EN;
    QString PRENOM_EN;
    int NB_HEURS;
    QString SPECIALITE;

};

#endif // ENSEIGNANTS_H
