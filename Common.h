#ifndef COMMON_H
#define COMMON_H
#include <QString>
#include <QDate>

namespace data_type{

typedef struct{
    QString Client;
    QString Mode_encaissement;
}recette_s;

typedef struct{
    QString Fournisseur_Designation;
    QString Mode_paiement;
}depense_s;

typedef struct{
    QDate Date;
    QString Ref;
    QString Nature;
    float Montant;
    recette_s recette;
    depense_s depense;
}data_type_s;

}
namespace table{
typedef enum{
    RECETTE = 0,
    DEPENSE
}table_s;
};//namespace table

#endif // COMMON_H
