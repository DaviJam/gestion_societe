#ifndef ABSTRACT_MODULE_H
#define ABSTRACT_MODULE_H

#include <database.h>

class Abstract_Module
{
public:
    Abstract_Module();

    void    addItem();
    // getter
    database::Database getDatabase() const;

protected:
    database::Database m_db;


};

#endif // ABSTRACT_MODULE_H
