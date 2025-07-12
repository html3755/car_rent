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
        QString text = QString::number(car->price);
        ui->price->setText(text);
        if(car->available == false){
            ui->pushButton->setText("Нет в наличии");
            ui->pushButton->setFlat(true);
        }
        if(car->type.contains("A")){
            QPixmap typeA(":/car_photos/photos/car_3.jpeg");
            ui->label->setPixmap(typeA);
            ui->label->setScaledContents(true);
        }
        if(car->type.contains("B")){
            QPixmap typeA(":/car_photos/photos/car_1.jpg");
            ui->label->setPixmap(typeA);
            ui->label->setScaledContents(true);
        }
        if(car->type.contains("C")){
            QPixmap typeA(":/car_photos/photos/car_5.jpeg");
            ui->label->setPixmap(typeA);
            ui->label->setScaledContents(true);
        }

    }
}

CarItem::~CarItem()
{
    delete ui;
}

int count = 0;
void CarItem::on_pushButton_clicked()
{
    if((MainSource->available == true) && (count == 0))
    {
    RentConfirmation *RentConf = new RentConfirmation;
    ui->verticalLayout->addWidget(RentConf);
    connect(RentConf, &RentConfirmation::onRentButtonClicked, this, CarItem::onRentButtonClicked);
    connect(RentConf, &RentConfirmation::onCancelButtonClicked, this, CarItem::onCancelClicked);
    this->RentConf = RentConf;
   count++;
    }
}

void CarItem::onRentButtonClicked(){
    ui->pushButton->setVisible(false);
    QLabel *rented = new QLabel("Арендовано!");
    ui->verticalLayout->addWidget(rented);
    ui->verticalLayout->removeWidget(RentConf);
    delete this->RentConf;
    this->RentConf = nullptr;
    count--;
    QFile file("E:/QT_project/car_rent/rentHistory/data.json");
    QJsonObject carJson = MainSource->toJson();
    QJsonArray carArray;
    if(file.open(QIODevice::ReadOnly)){
        QByteArray data = file.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        carArray = doc.array();
        file.close();
    }
    carArray.append(carJson);
    if(file.open(QIODevice::WriteOnly)){
        qDebug()<<"файл открылся";
        QJsonDocument doc(carArray);
        file.write(doc.toJson());
        file.close();
    }
}

void CarItem::onCancelClicked(){
    ui->verticalLayout->removeWidget(RentConf);
    delete this->RentConf;
    this->RentConf = nullptr;
    count--;
}

bool CarItem::matchesFilter(const QString& filterText){
    if (filterText == "любая"){
        return true;
    }
    return ui->type->text().contains(filterText);
}



