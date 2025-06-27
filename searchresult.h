#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H
#include "car.h"
#include "caritem.h"
#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonArray>


namespace Ui {
class SearchResult;
}

class SearchResult : public QWidget
{
    Q_OBJECT

public:
    QJsonDocument data;
    QFile file;
    QString datapath;
    explicit SearchResult(QWidget *parent = nullptr);
    ~SearchResult();
    Ui::SearchResult *ui;
    void clear();
   // void fill(QList<Car*> items);
private:
    Car* car1;
};

#endif // SEARCHRESULT_H
