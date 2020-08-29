#include "widgetfilldata.h"
#include "ui_widgetfilldata.h"

WidgetFillData::WidgetFillData(QWidget *parent, table::table_s ai_tableType) :
    QWidget(parent),
    ui(new Ui::WidgetFillData),
    m_tableType(ai_tableType)
{
    ui->setupUi(this);
    initWidget();

    connect(ui->pushButton,&QPushButton::pressed,this, [=]()
    {
        emit sendData(getData());
        close();
    });
    connect(ui->pushButton_2,&QPushButton::pressed,this, &WidgetFillData::close);
}

WidgetFillData::~WidgetFillData()
{
    delete ui;
}

void WidgetFillData::initWidget()
{
    ui->label->setText("Remplir tous les champs avant de valider.");

    ui->Date_label->setText("Date : ");
    ui->Ref_label->setText("Référence : ");
    ui->Nature_label->setText("Nature : ");
    ui->Montant_label->setText("Montant : ");
    if(m_tableType == table::RECETTE)
    {
        ui->Client_label->setText("Client : ");
        ui->Mode_label->setText("Mode d'encaissement : ");
    }
    else
    {
        ui->Client_label->setText("Fournisseur/Designation : ");
        ui->Mode_label->setText("Mode de paiement : ");
    }
}
data_type::data_type_s WidgetFillData::getData()
{
    m_data.Ref="";
    m_data.Date=QDate::currentDate();
    m_data.Nature="";
    m_data.Montant=0;
    if(m_tableType == table::RECETTE)
    {
        m_data.recette.Client="";
        m_data.recette.Mode_encaissement="";
    }
    else
    {
        m_data.depense.Fournisseur_Designation="";
        m_data.depense.Mode_paiement="";
    }

    if(m_tableType == table::RECETTE)
    {
        m_data.recette.Client = ui->Client_edit->text();
        m_data.recette.Mode_encaissement = ui->Mode_edit->text();
    }
    else
    {
        m_data.depense.Fournisseur_Designation = ui->Client_edit->text();
        m_data.depense.Mode_paiement = ui->Mode_edit->text();
    }

    m_data.Ref = ui->Ref_edit->text();
    m_data.Date = ui->dateEdit->date();
    m_data.Nature = ui->Nature_edit->text();
    m_data.Montant = ui->Montant_edit->text().toFloat();
    return m_data;
}
