#ifndef CAR_H
#define CAR_H

#include <qstring.h>
#include <qjsonobject.h>
#include <qlabel.h>

class Car
{
public:
    Car();
    Car(QString name, QString description, QString type, double price, bool available);
    Car(QJsonObject json);

    bool available;
    QString name;
    QString description;
    QString type;
    double price;
public slots:
    QJsonObject toJson();
};



#endif // CAR_H
