#include "searchresult.h"
#include "ui_searchresult.h"
#include "mainwindow.h"


SearchResult::SearchResult(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchResult)
{
    ui->setupUi(this);
    datapath = QFileDialog::getOpenFileName(nullptr,"","./database","*.json");
    file.setFileName(datapath);
    file.open(QIODevice::ReadOnly|QFile::Text);
    data = QJsonDocument::fromJson(file.readAll());


    foreach(QJsonValue value, data.array()) {
        QJsonObject object = value.toObject();
        Car* car = new Car(object);
    }
}

SearchResult::~SearchResult()
{
    delete ui;
}

