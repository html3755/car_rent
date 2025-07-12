#ifndef CARITEM_H
#define CARITEM_H

#include <QWidget>
#include "car.h"
#include "rentconfirmation.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFileDialog>

namespace Ui {
class CarItem;
}

class CarItem : public QWidget
{
    Q_OBJECT

public:
    explicit CarItem(Car* MainSource = nullptr, QWidget *parent = nullptr);
    ~CarItem();
    Ui::CarItem *ui;
public slots:
    void onRentButtonClicked();
    bool matchesFilter(const QString& filterText);
    void onCancelClicked();
private slots:
    void on_pushButton_clicked();
signals:
   void onConfirm();

private:
    RentConfirmation* RentConf;
    Car* MainSource;
};

#endif // CARITEM_H
