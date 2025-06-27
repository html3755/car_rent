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
