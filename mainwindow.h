#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static MainWindow*  _create();
    ~MainWindow();

    MainWindow* instance(void);

private:
    Ui::MainWindow *ui;
    QPalette w_palette; //warning
    QPalette c_palette; //common
};

#endif // MAINWINDOW_H
