#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QtCore>
#include <QMessageBox>
#include <QCloseEvent>
#include <QLayout>
#include <QFile>

static MainWindow* _instance = NULL;

MainWindow* MainWindow::_create()
{
    Q_ASSERT(_instance == NULL);
    _instance = new MainWindow();
    Q_ASSERT(_instance);
    return _instance;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(960,600);
    this->setStyleSheet("QPushButton {background: #cfe2f3}"
                        "QPushButton:pressed {background: 6699cc}");

    c_palette.setColor(QPalette::WindowText,Qt::black);
    w_palette.setColor(QPalette::WindowText,Qt::red);

    show();
}

 MainWindow* MainWindow::instance(void)
 {
     return _instance;
 }

MainWindow::~MainWindow()
{
    _instance = NULL;
    delete ui;
}
