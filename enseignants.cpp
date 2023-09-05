#include "enseignants.h"

ENSEIGNANTS::ENSEIGNANTS()
{

}
ENSEIGNANTS::ENSEIGNANTS(int a,QString b,QString c,int d,QString e)
{
  ID_EN=a;
  NOM_EN=b;
  PRENOM_EN=c;
  NB_HEURS=d;
  SPECIALITE=e;

}
bool ENSEIGNANTS::ajoutere(){
    QSqlQuery query;
    QString res = QString::number(ID_EN);

    query.prepare("insert into ENSEIGNANT(ID_EN,NOM_EN,PRENOM_EN,NB_HEURS,SPECIALITE)""values(:ID_EN,:NOM_EN,:PRENOM_EN,:NB_HEURS,:SPECIALITE)");

    query.bindValue(":ID_EN",ID_EN);
    query.bindValue(":NOM_EN",NOM_EN);
    query.bindValue(":PRENOM_EN",PRENOM_EN);
    query.bindValue(":NB_HEURS",NB_HEURS);
    query.bindValue(":SPECIALITE",SPECIALITE);



    return query.exec();


}
QSqlQueryModel * ENSEIGNANTS::affichere()
{
    QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from ENSEIGNANT ");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EN"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EN"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_EN"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("NB_HEURS"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("SPECIALITE"));



     return  model;

}
bool ENSEIGNANTS::modifiere(){
    QSqlQuery query;
    query.prepare("UPDATE ENSEIGNANT SET  NOM_EN=:NOM_EN , PRENOM_EN=:PRENOM_EN , NB_HEURS=:NB_HEURS,SPECIALITE=:SPECIALITE   where ID_EN=:ID_EN ");

    query.bindValue(":ID_EN",ID_EN);
    query.bindValue(":NOM_EN",NOM_EN);
    query.bindValue(":PRENOM_EN",PRENOM_EN);
    query.bindValue(":NB_HEURS",NB_HEURS);
    query.bindValue(":SPECIALITE",SPECIALITE);

    return    query.exec();
}

QSqlQueryModel * ENSEIGNANTS::setide()
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select DISTINCT ID_EN from ENSEIGNANT");
     model->setHeaderData(0,Qt::Horizontal,"ID_EN");

     return model;
 }
bool ENSEIGNANTS::supprimere(int id){
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("delete from ENSEIGNANT where ID_EN= :ID_EN");
    query.bindValue(":ID_EN",res);

    return query.exec();

}
QSqlQueryModel * ENSEIGNANTS::affichere5(QString a)
 {  QSqlQueryModel * model = new QSqlQueryModel();


    model->setQuery("select * from ENSEIGNANT order by "+a+" desc");//asc pour ascendant et desc pour descendant.

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EN"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_EN"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NB_HEURS"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("SPECIALITE"));


    return model;
 }
QSqlQueryModel * ENSEIGNANTS::affichere4(QString a,QString b)
{
  QSqlQueryModel * model = new QSqlQueryModel();

  model->setQuery("select * from ENSEIGNANT WHERE "+a+" LIKE '%"+b+"%'");

  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EN"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_EN"));
  model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_EN"));
  model->setHeaderData(3,Qt::Horizontal,QObject::tr("NB_HEURS"));
  model->setHeaderData(4,Qt::Horizontal,QObject::tr("SPECIALITE"));

   return model;
}
