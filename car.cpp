#include "Car.h"

Car::Car() {}

Car::Car(QString name, QString description, QString type, QString price, bool available) {
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
    this->price = json["price"].toString();
    this->available = json["available"].toBool();
}
