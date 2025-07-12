#include "rentconfirmation.h"
#include "ui_rentconfirmation.h"


RentConfirmation::RentConfirmation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RentConfirmation)

{
    ui->setupUi(this);
}

RentConfirmation::~RentConfirmation()
{
    delete ui;
}

void RentConfirmation::on_rentButton_clicked()
{
    emit onRentButtonClicked();
 //   emit whenRented();
}


void RentConfirmation::on_cancelButton_clicked()
{
    emit onCancelButtonClicked();
}

