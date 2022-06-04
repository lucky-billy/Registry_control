#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "samsungmachinecontrol.h"
//#include "bmachinecontrol_32.h"
//#include "bmachinecontrol.h"
#include "bmachinecontrol_64.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_getInfoBtn_clicked();

    void on_createBtn_clicked();

    void on_activeBtn_clicked();

private:
    Ui::MainWindow *ui;
//    SamsungMachineControl *m_machine;
//    BMachineControl_32 *m_machine;
    BMachineControl_64 *m_machine;
};
#endif // MAINWINDOW_H
