#ifndef WIDGETRECETTEDEPENSE_H
#define WIDGETRECETTEDEPENSE_H

#include <QWidget>
#include "interface.h"
#include "Common.h"

namespace Ui {
class WidgetRecetteDepense;
}

class WidgetRecetteDepense : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetRecetteDepense(QWidget *parent = nullptr);
    ~WidgetRecetteDepense();

    //getter
    Interface* getRecetteInterface() const { return widget_recette; }
    Interface* getDepenseInterface() const { return widget_depense; }
signals:
    void recetteAddButtonPressed();
    void recetteRemoveButtonPressed();
    void depenseAddButtonPressed();
    void depenseRemoveButtonPressed();
    void addRecette(table::table_s ai_table);
    void removeRecette(table::table_s ai_table);

private:
    Ui::WidgetRecetteDepense *ui;
    Interface* widget_recette;
    Interface* widget_depense;
};

#endif // WIDGETRECETTEDEPENSE_H
