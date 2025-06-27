#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "searchresult.h"

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
private slots:
 //   void MainWindow::on_pushButton_clicked();
private:
    SearchResult* searchresult;
};
#endif // MAINWINDOW_H
