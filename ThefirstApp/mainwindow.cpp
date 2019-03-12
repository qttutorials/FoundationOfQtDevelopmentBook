#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //
    connect(ui->pushButtonAdd,SIGNAL(pressed()),this,SLOT(addItem()));
    connect(ui->pushButtonDel,SIGNAL(pressed()),this,SLOT(deleteItem()));
    connect(ui->pushButtonClear,SIGNAL(pressed()),this,SLOT(clearAll()));
    connect(ui->pushButtonEdit,SIGNAL(pressed()),this,SLOT(editItem()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addItem(void)
{
    Dialog dlg;
    if(dlg.exec() == QDialog::Accepted)
    {
        ui->listWidget->addItem(dlg.getName() + " -- " + dlg.getNumber());
    }
}

void MainWindow::deleteItem()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void MainWindow::clearAll()
{
    ui->listWidget->clear();
}

void MainWindow::editItem()
{
    if(!ui->listWidget->currentItem()) return;

    Dialog dlg1;
    QStringList parts = ui->listWidget->currentItem()->text().split(" -- ");
    dlg1.setName(parts[0]);
    dlg1.setNumber(parts[1]);

    if(dlg1.exec() == QDialog::Accepted)
    {
        ui->listWidget->currentItem()->setText(dlg1.getName() + " -- " + dlg1.getNumber());
    }
}
