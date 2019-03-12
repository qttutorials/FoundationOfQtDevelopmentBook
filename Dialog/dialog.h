#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    const QString getName() const;
    void setName(const QString&);

    const QString getNumber() const;
    void setNumber(const QString&);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
