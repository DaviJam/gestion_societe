#include "interface.h"
#include "ui_interface.h"
#include <QDebug>

int Interface::rowDepense = 0;
int Interface::rowRecette = 0;
int Interface::currentIndex = 0;
Interface::Interface(QWidget *parent, table::table_s ai_table) :
    QWidget(parent),
    ui(new Ui::Form),
    m_tableType(ai_table)
{
    ui->setupUi(this);
    m_dataModel = new QStandardItemModel(this);
    connect(ui->pushButton, &QPushButton::pressed, this, &Interface::addButtonPressed);
    connect(ui->pushButton_2, &QPushButton::pressed, this, &Interface::removeButtonPressed);
}

Interface::~Interface()
{
    delete m_dataModel;
}

void Interface::addButtonPressed()
{
    filler = new WidgetFillData(nullptr, m_tableType);
    connect(filler, &WidgetFillData::sendData, this, &Interface::addToTable);
    filler->show();
    //filler->deleteLater();
}

void Interface::removeButtonPressed()
{
    m_dataModel->removeRow(ui->tableView->currentIndex().row());
}

void Interface::addToTable(data_type::data_type_s ai_data)
{
    disconnect(filler, &WidgetFillData::sendData, this, &Interface::addToTable);
    QVector<QString> datas;
    datas << ai_data.Date.toString()
          << ai_data.Ref
          << ai_data.Nature
          << QString::number(static_cast<double>(ai_data.Montant),'g',6);
    if(m_tableType == table::RECETTE)
    {
        datas << ai_data.recette.Client
              << ai_data.recette.Mode_encaissement;
    }
    else
    {
        datas << ai_data.depense.Mode_paiement
              << ai_data.depense.Fournisseur_Designation;
    }

    QStringList headerList;
    headerList << "Date"
               << "Référence"
               << "Nature"
               << "Montant";
    if(m_tableType == table::RECETTE)
    {
         headerList << "Client"
                    << "Mode d'encaissement";
    }
    else
    {
        headerList << "Fournisseur/Designation"
                   << "Mode de paiement";
    }

    QList<QStandardItem*> itemList;
    for (int column = 0; column < 6; ++column) {
        QStandardItem *item = new QStandardItem(datas.at(column));
        itemList << item;
    }
    m_dataModel->appendRow(itemList);
    m_dataModel->setHorizontalHeaderLabels(headerList);
    ui->tableView->setModel(m_dataModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->update();
    //inform database to save data
    emit registrationReady(data_type::data_type_s ai_data);
}
