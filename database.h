#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlTableModel>
#include <QDate>
#include "Common.h"

namespace database{

class Database
{
public:
    Database();
    static void add_to_database(table::table_s ai_table, data_type::data_type_s data);

private:
    QSqlDatabase m_database;
};
};//namespase database
#endif // DATABASE_H
