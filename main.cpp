#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QObject>

using namespace std;

class Stared: public QObject{
public:
    Stared(void){
        emit started();
    }

signals:
    void started(void);
};

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
