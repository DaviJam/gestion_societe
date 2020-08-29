#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widgetrecettedepense.h"
#include <QDate>
#include <QString>
#include <QTableView>
#include <QPushButton>
#include <QDebug>
#define NB_MONTHS 12
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont serifFont("Times", 20, QFont::Bold);
    ui->label->setFont(serifFont);
    ui->label->setText(QString("Année %1").arg(QString::number(QDate::currentDate().year())));
    ui->label->setScaledContents(true);
    for(int i = 0; i < NB_MONTHS; i++)
    {
        WidgetRecetteDepense* widget = new WidgetRecetteDepense(ui->tabWidget);
        QList<QObject*> list;
        list << widget;
        m_objectList << list;
        widget->adjustSize();
        ui->tabWidget->addTab(widget, QDate(2000,i+1,1).toString("MMMM"));
        ui->tabWidget->currentWidget()->adjustSize();

    }
}

MainWindow::~MainWindow()
{
    for(auto* item : *m_objectList.data())
    {
        item->deleteLater();
    }
    m_objectList.clear();
    delete ui;
}
