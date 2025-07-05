#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "car.h"
#include "searchresult.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->searchresult = new SearchResult;
    ui->verticalLayout_6->addWidget(this->searchresult);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->searchresult;
}
void MainWindow::on_pushButton_clicked(){

}

