#ifndef RENTCONFIRMATION_H
#define RENTCONFIRMATION_H

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

private:
    Ui::RentConfirmation *ui;
};

#endif // RENTCONFIRMATION_H
