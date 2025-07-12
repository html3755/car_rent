#ifndef RENTCONFIRMATION_H
#define RENTCONFIRMATION_H
#include "car.h"
#include <QWidget>

namespace Ui {
class RentConfirmation;
}

class RentConfirmation : public QWidget
{
    Q_OBJECT

public:
    explicit RentConfirmation(QWidget *parent = nullptr);
    ~RentConfirmation();
public slots:
    void on_rentButton_clicked();
private slots:

    void on_cancelButton_clicked();

signals:
    void onRentButtonClicked();
    void onCancelButtonClicked();
//    void whenRented();
private:
    Ui::RentConfirmation *ui;
};

#endif // RENTCONFIRMATION_H
