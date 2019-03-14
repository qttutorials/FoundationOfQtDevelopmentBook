#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //
    setAttribute(Qt::WA_DeleteOnClose); //make Qt delete this widget when
                                        //the widget has accepted the close event
    setWindowTitle(QString("%1[*] - %2").arg("unnamed").arg("SDI"));

    docWidget = new QTextEdit(this);
    setCentralWidget(docWidget);

    //set changes property for MainWindow
    connect(docWidget->document(),SIGNAL(modificationChanged(bool)),this,SLOT(setWindowModified(bool)));

    createActions();
    createMenus();
    createToolbars();
    statusBar()->showMessage("Done");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions()
{
    newAction = new QAction(QIcon(":/images/new.png"),tr("&New"),this);
    newAction->setShortcut(tr("Ctrl+N"));
    newAction->setStatusTip(tr("Create a new document"));
    connect(newAction,SIGNAL(triggered(bool)),this,SLOT(fileNew()));

}

void MainWindow::createMenus()
{
    QMenu *menu;

    menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(newAction);

    menu->addSeparator();
}

void MainWindow::createToolbars()
{
    QToolBar *toolbar;

    toolbar = addToolBar(tr("File"));
    toolbar->addAction(newAction);
}

void MainWindow::fileNew()
{
    (new MainWindow())->show();
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    if(isSafeToClose())
        event->accept();
    else
        event->ignore();
}


bool MainWindow::isSafeToClose()
{
    if(isWindowModified())
    {
        switch (QMessageBox::warning(this,tr("SDI"),tr("The document has unsaved changes.\n"
                                    "Do you want to save it before it is closed?"),QMessageBox::Discard |
                                     QMessageBox::Cancel)) {
        case QMessageBox::Cancel:
            return false;
            break;
        default:
            return true;
            break;
        }
    }
    return true;
}
