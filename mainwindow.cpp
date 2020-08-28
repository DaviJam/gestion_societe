#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont serifFont("Times", 20, QFont::Bold);
    ui->label->setFont(serifFont);
    ui->label->setText(QString("Année %1").arg(QString::number(QDate::currentDate().year())));
    ui->label->setScaledContents(true);
    for(int i = 0; i < 12; i++)
    {
        QWidget* widget = new QWidget(ui->tabWidget);
        m_tabWidgetList << widget;
        ui->tabWidget->addTab(widget, QDate(2000,i+1,1).toString("MMMM"));
        //ui->tabWidget->setTabText(i, QDate(2000,i+1,1).toString("MMMM"));
    }
}

MainWindow::~MainWindow()
{
    m_tabWidgetList.clear();
    delete ui;
}

