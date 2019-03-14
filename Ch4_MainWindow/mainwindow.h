#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTextEdit>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    //members
    QTextEdit *docWidget;
    QAction *newAction;
    QAction *closeAction;

    //methods
    void createActions();
    void createMenus();
    void createToolbars();
    bool isSafeToClose();

private slots:
    void fileNew(void);

protected:
    //reimplement QWidget::closeEvent()
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;
};

#endif // MAINWINDOW_H
