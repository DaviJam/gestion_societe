#ifndef WIDGETFILLDATA_H
#define WIDGETFILLDATA_H

#include <QWidget>
#include <Common.h>

namespace Ui {
class WidgetFillData;
}

class WidgetFillData : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetFillData(QWidget *parent = nullptr,  table::table_s ai_tableTyp = table::RECETTE);
    ~WidgetFillData();

signals:
void sendData(data_type::data_type_s ai_data);

private:
    Ui::WidgetFillData *ui;
    table::table_s m_tableType;
    data_type::data_type_s m_data;

    void initWidget();
    data_type::data_type_s getData();
};

#endif // WIDGETFILLDATA_H
