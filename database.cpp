#include "database.h"
#include <QString>
#include <QDate>
#include <QDebug>

namespace database{
Database::Database()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName("gestion.db");
    m_database.open();
    if(m_database.isOpen())
    {
        int w_annee = QDate::currentDate().year();
        QSqlQuery query(m_database);
        // Crée la table Recettes
        query.prepare(QString("CREATE TABLE IF NOT EXISTS Recettes_%1 ("
                              "Date DATE "
                              "Ref TEXT "
                              "Client TEXT "
                              "Nature TEXT "
                              "Montant FLOAT "
                              "Mode_encaissement TEXT"
                              ")").arg(w_annee));
        if(!query.exec())
        {
            qDebug() << "Failed to create Table Recettes_" << w_annee;
        }
        // Crée la table Dépenses
        query.prepare(QString("CREATE TABLE IF NOT EXISTS Depenses_%1 ("
                              "Date date "
                              "Ref TEXT "
                              "Fournisseur_Designation TEXT "
                              "Nature TEXT "
                              "Montant FLOAT "
                              "Mode_paiement TEXT"
                              ")").arg(w_annee));
        if(!query.exec())
        {
            qDebug() << "Failed to create Table Depenses_" << w_annee;
        }
    }
    else
        qDebug() << "Failed to open m_database";

}
}
