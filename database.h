#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlTableModel>

namespace database{

namespace table{

    typedef enum{
        RECETTE = 0,
        DEPENSE
}table_s;
};//namespace table

class Database
{
public:
    Database();
    static void add_to_database(table::table_s ai_dataType);

private:
    QSqlDatabase m_database;
};
};//namespase database
#endif // DATABASE_H
