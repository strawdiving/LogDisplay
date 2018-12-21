#ifndef LOGWIDGET_H
#define LOGWIDGET_H

/** Load and parse log file, if you select parameters,it will plot for you
  **/
#include <QWidget>
#include "LogAnalysis.h"
#include "chartView.h"
#include <QTreeWidget>
#include <QPair>
#include <QMap>
#include <QGraphicsSimpleTextItem>
#include <QSqlQueryModel>
#include "Callout.h"

namespace Ui {
class LogWidget;
}

class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget *parent = 0);
    ~LogWidget();

private slots:
    /// load log file, parse and store log data
    void on_pushButton_OpenLogFile_clicked();
    /// plot the selected data
    void plotData(QTreeWidgetItem* item, int column);
   //void keepCallout();
    /// called when mouse is hovering on line series to show data of point
    void tooltip(QPointF point, bool state);
    void _openFileStatusChanged(bool opened);

    void on_pushButton_Clear_clicked();

protected:
    //void mouseMoveEvent(QMouseEvent* event);

private:
    void _init(); /// initialize widget
    void _clear(); /// clear table and chart

    Ui::LogWidget *ui;

    LogAnalysis* _logAnalysis; /// object to parse and store log data
    QSqlQueryModel *model;

    chartView* _chartView; /// chart view
    QChart* _chart;
    QGraphicsSimpleTextItem *_coordX;
    QGraphicsSimpleTextItem *_coordY;
    Callout *_tooltip;  /// tooltip box displaying data of point

    ///key: QTreeWidgetItem
    /// value: filePath
    QMap<QTreeWidgetItem*,QStringList> _item2FilepathMap;
};

#endif // LOGWIDGET_H
