#include "caritem.h"
#include "ui_caritem.h"

CarItem::CarItem(Car *car, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CarItem)
{
    ui->setupUi(this);
    this->MainSource = car;

    if (car != nullptr) {
        ui->name->setText(car->name);
        ui->description->setText(car->description);
        ui->type->setText(car->type);
        ui->price->setText(car->price);

    }
}

CarItem::~CarItem()
{
    delete ui;
}

void CarItem::on_pushButton_clicked()
{
    this->RentConf = new RentConfirmation;
    ui->verticalLayout->addWidget(this->RentConf);
}

