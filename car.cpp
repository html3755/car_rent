#include "Car.h"

Car::Car() {}

Car::Car(QString name, QString description, QString type, double price, bool available) {
    this->name = name;
    this->description = description;
    this->type = type;
    this->price = price;
    this->available = available;
}

Car::Car(QJsonObject json) {
    this->name = json["name"].toString();
    this->description = json["description"].toString();
    this->type = json["type"].toString().at(0);
    this->price = json["price"].toDouble();
    this->available = json["available"].toBool();
}
QJsonObject Car::toJson(){
    QJsonObject result;
    result["name"] = name;
    result["price"] = price;
    return result;
}
