#ifndef QUADAPPLICATION_H
#define QUADAPPLICATION_H

#include <QApplication>
#include "mainwindow.h"
//class MainWindow;

class QuadApplication : public QApplication
{

public:
    QuadApplication(int &argc, char* argv[]);
    ~QuadApplication();

    static QuadApplication* _app;
    bool _initForNormalAppBoot(void);

    MainWindow* mainWindow(void) {return _mainwindow;}
    void showMessage(QString message);

private:
    MainWindow* _mainwindow;
};

QuadApplication* qgcApp();
#endif // QUADAPPLICATION_H
