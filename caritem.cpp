#include "caritem.h"
#include "ui_caritem.h"

CarItem::CarItem(Car *car, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CarItem)
{
    ui->setupUi(this);
    this->MainSource = car;
    ui->label->setFixedWidth(399);
    ui->label->setFixedHeight(280);
    if (car != nullptr) {
        ui->name->setText(car->name);
        ui->description->setText(car->description);
        ui->type->setText(car->type);
        ui->price->setText(car->price);
        if(car->available == false){
            ui->pushButton->setText("Нет в наличии");
            ui->pushButton->setFlat(true);
        }
        if(car->type == 'A' ){
            QPixmap typeA(":/photos/car_1.jpg");
            ui->label->setPixmap(typeA);
        }

    }
}

CarItem::~CarItem()
{
    delete ui;
}

void CarItem::on_pushButton_clicked()
{
    if(MainSource->available == true)
    {
    this->RentConf = new RentConfirmation;
    ui->verticalLayout->addWidget(this->RentConf);
    }
}


