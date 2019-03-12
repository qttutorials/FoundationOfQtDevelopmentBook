#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addItem(void);
    void deleteItem(void);
    void editItem(void);
    void clearAll(void);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
