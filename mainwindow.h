#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "searchresult.h"
#include "rentconfirmation.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
public slots:
    void on_pushButton_clicked();
//    void whenRented();
signals:
    void onSearchClicked();
private:
    SearchResult* searchresult;
    RentConfirmation* rf;
    Car* car;
};
#endif // MAINWINDOW_H
