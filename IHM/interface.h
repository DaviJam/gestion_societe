#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include <QWidget>
#include <QStandardItemModel>
#include "Common.h"
#include "widgetfilldata.h"

QT_BEGIN_NAMESPACE
namespace Ui {class Form;}
QT_END_NAMESPACE

class Interface : public QWidget
{
    Q_OBJECT
public:
    Interface(QWidget *parent = nullptr, table::table_s ai_table = table::RECETTE);
    ~Interface();
    static int rowRecette;
    static int rowDepense;
    static int currentIndex;

protected slots:
    void addToTable(data_type::data_type_s ai_data);
    void addButtonPressed();
    void removeButtonPressed();
private:
    Ui::Form* ui;
    table::table_s m_tableType;
    QStandardItemModel* m_dataModel;
    WidgetFillData* filler;
};

#endif // INTERFACE_H
