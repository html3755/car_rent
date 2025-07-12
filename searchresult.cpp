#include "searchresult.h"
#include "ui_searchresult.h"
#include "mainwindow.h"


SearchResult::SearchResult(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchResult)
{
    ui->setupUi(this);
    datapath = QFileDialog::getOpenFileName(nullptr,"",":/database","*.json");
    file.setFileName(datapath);
    file.open(QIODevice::ReadOnly|QFile::Text);
    data = QJsonDocument::fromJson(file.readAll());


    foreach(QJsonValue value, data.array()) {
        QJsonObject object = value.toObject();
        Car* car = new Car(object);
        onJsonFileReading(car);
    }
    file.close();
}

void SearchResult::onJsonFileReading(Car* car) {

    CarItem* caritem = new CarItem(car, this);

    ui->scrollArea->widget()->layout()->addWidget(caritem);
}


SearchResult::~SearchResult()
{
    delete ui;
}

void SearchResult::onSearch(const QString& filterText){
    QList<CarItem*> carItems = this->findChildren<CarItem*>();
    for (CarItem* item : carItems){
        if(item->matchesFilter(filterText)){
            item->show();
        }
        else{
            item->hide();
        }
    }

}
