#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //Chỉ cho phép nhập số.
    ui->lineEditNumber->setValidator(new QIntValidator());
}

Dialog::~Dialog()
{
    delete ui;
}

const QString Dialog::getName() const
{
    return ui->lineEditName->text();
}

const QString Dialog::getNumber() const
{
    return ui->lineEditNumber->text();
}

void Dialog::setName(const QString &name)
{
    ui->lineEditName->setText(name);
}

void Dialog::setNumber(const QString &number)
{
    ui->lineEditNumber->setText(number);
}
