#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Registry");
    setMaximumSize(this->width(), this->height());
    setMinimumSize(this->width(), this->height());

    m_machine = new SamsungMachineControl();
//    m_machine = new BMachineControl_32();
//    m_machine = new BMachineControl_64();
}

MainWindow::~MainWindow()
{
    delete m_machine;
    delete ui;
}

void MainWindow::on_getInfoBtn_clicked()
{
    QString info = m_machine->getInfo();
    ui->textEdit->setText(info);
}

void MainWindow::on_createBtn_clicked()
{
    QDateTime datatime(QDateTime::currentDateTime());
    QString date = datatime.toString("ddMMyyyy");

    int month = 0;
    switch ( ui->comboBox->currentIndex() )
    {
    case 0: month = 1; break;
    case 1: month = 3; break;
    case 2: month = 6; break;
    case 3: month = 12; break;
    case 4: month = 1000000; break;
    default: month = 0; break;
    }

    if ( ui->textEdit->toPlainText() == "" ) {
        QMessageBox::critical(nullptr, "error", "No machine info !", QMessageBox::Ok);
    } else {
        QString key = m_machine->getKey(ui->textEdit->toPlainText(), date, month, ui->radioButton->isChecked());
        ui->lineEdit->setText(key);
    }
}

void MainWindow::on_activeBtn_clicked()
{
    bool ret = m_machine->activeKey( ui->lineEdit->text(), ui->radioButton->isChecked());
    if (ret) {
        QMessageBox::information(nullptr, "info", "Registered successfully !", QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, "error", "Registered failed !", QMessageBox::Ok);
    }
}
