#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_GPIO_clicked(bool);
    void on_Button_clicked(bool);

private slots:
    void checkEnable();
    void checkDisable();
private:
    Ui::MainWindow *ui;
    void IRLabel(QString name);
    void LEDLabel(QString name);
   // void blink(int time);
};

#endif // MAINWINDOW_H
