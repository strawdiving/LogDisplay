#ifndef LOGANALYSIS_H
#define LOGANALYSIS_H

/** Parse log file, and store log data in database
  **/
#include <QWidget>
#include <QMap>
#include <QSqlDatabase>
#include "basic_types.h"
#include "messages.h"
#include "sdfiles.h"

class LogAnalysis : public QWidget
{
    Q_OBJECT
public:
    LogAnalysis(QWidget *parent);
    /// load log file, parse and store log data
    void logReadAndStore();

signals:
    void openFileStatusChanged(bool opened);

private:
    /// create database and tables of each kind of log data
    bool _creatConnection();

    QSqlDatabase db;
};

#endif // LOGANALYSIS_H
