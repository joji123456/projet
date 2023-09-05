#ifndef GARDERIE_H
#define GARDERIE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class garderie
{
public:

    QSqlQueryModel * setid();

    bool ajouter();

    bool supprimer(int );
    bool modifier();
    bool modifiert();
    QSqlQueryModel * afficher() ;
    QSqlQueryModel * afficher5(QString a);
    QSqlQueryModel * afficher4(QString a,QString b);
    garderie();
    garderie(int ,QString ,QString ,QString ,int,QString);


private:
    int ID_EL;
    QString NOM;
    QString PRENOM;
    QString CLASSE;
    int AGE;
    QString PHOTO;

};



#endif // GARDERIE_H
