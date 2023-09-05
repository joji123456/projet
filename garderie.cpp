#include "garderie.h"

garderie::garderie()
{

}

garderie::garderie(int a,QString b,QString c,QString d,int e,QString f){
    ID_EL=a;
    NOM=b;
    PRENOM=c;
    CLASSE=d;
    AGE=e;
    PHOTO=f;
}
bool garderie::ajouter(){
    QSqlQuery query;
    QString res = QString::number(ID_EL);

    query.prepare("insert into ELEVE(ID_EL,NOM,PRENOM,CLASSE,AGE,PHOTO)""values(:ID_EL,:NOM,:PRENOM,:CLASSE,:AGE,:PHOTO)");

    query.bindValue(":ID_EL",ID_EL);
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":CLASSE",CLASSE);
    query.bindValue(":AGE",AGE);
    query.bindValue(":PHOTO",PHOTO);


    return query.exec();


}
QSqlQueryModel * garderie::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from ELEVE ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EL"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("CLASSE"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("AGE"));
     model->setHeaderData(5,Qt::Horizontal,QObject::tr("PHOTO"));


     return  model;

}
bool garderie::supprimer(int id){
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("delete from ELEVE where ID_EL= :ID_EL");
    query.bindValue(":ID_EL",res);

    return query.exec();

}
bool garderie::modifier(){
    QSqlQuery query;
    query.prepare("UPDATE ELEVE SET  NOM=:NOM , PRENOM=:PRENOM , CLASSE=:CLASSE , AGE=:AGE ,PHOTO=:PHOTO  where ID_EL=:ID_EL ");

    query.bindValue(":ID_EL",ID_EL);
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":CLASSE",CLASSE);
    query.bindValue(":AGE",AGE);
    query.bindValue(":PHOTO",PHOTO);
    return    query.exec();
}

QSqlQueryModel * garderie::setid()
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select DISTINCT ID_EL from ELEVE");
     model->setHeaderData(0,Qt::Horizontal,"ID_EL");

     return model;
 }

QSqlQueryModel * garderie::afficher5(QString a)
 {  QSqlQueryModel * model = new QSqlQueryModel();


    model->setQuery("select * from ELEVE order by "+a+" desc");//asc pour ascendant et desc pour descendant.

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EL"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("CLASSE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("AGE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PHOTO"));

    return model;
 }
QSqlQueryModel * garderie::afficher4(QString a,QString b)
{
  QSqlQueryModel * model = new QSqlQueryModel();

  model->setQuery("select * from ELEVE WHERE "+a+" LIKE '%"+b+"%'");

  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EL"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("CLASSE"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("AGE"));
  model->setHeaderData(5,Qt::Horizontal,QObject::tr("PHOTO"));

   return model;
}


