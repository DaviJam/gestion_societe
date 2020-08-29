#include "widgetrecettedepense.h"
#include "ui_widgetrecettedepense.h"

WidgetRecetteDepense::WidgetRecetteDepense(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetRecetteDepense)
{
    ui->setupUi(this);
    widget_recette = new Interface(this,table::RECETTE);
    widget_depense = new Interface(this,table::DEPENSE);

    QVBoxLayout* VBox = new QVBoxLayout(this);
    VBox->addWidget(widget_recette);
    VBox->addSpacerItem(new QSpacerItem(10,10, QSizePolicy::MinimumExpanding, QSizePolicy::Fixed));
    VBox->addWidget(widget_depense);
    ui->gridLayout->addLayout(VBox,0,0,Qt::AlignCenter);
    ui->gridLayout->setSpacing(2);
}

WidgetRecetteDepense::~WidgetRecetteDepense()
{
    delete ui;
}
