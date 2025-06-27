#ifndef CAR_H
#define CAR_H

#include <qstring.h>
#include <qjsonobject.h>
#include <qlabel.h>

class Car
{
public:
    Car();
    Car(QString name, QString description, QString type, QString price);
    Car(QJsonObject json);


    QString name;
    QString description;
    QString type;
    QString price;
};

#endif // CAR_H
