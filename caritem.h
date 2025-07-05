#ifndef CARITEM_H
#define CARITEM_H

#include <QWidget>
#include "car.h"
#include "rentconfirmation.h"

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
private slots:
    void on_pushButton_clicked();

private:

    Car* MainSource;
    RentConfirmation* RentConf;
};

#endif // CARITEM_H
