#include <QApplication>
#include "mainwindow.h"
#include "machineinformation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

//    MachineInformation w2;
//    w2.show();

    return a.exec();
}
