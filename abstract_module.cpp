#include "abstract_module.h"

Abstract_Module::Abstract_Module()
{

}

database::Database Abstract_Module::getDatabase() const
{
    return m_db;
}
