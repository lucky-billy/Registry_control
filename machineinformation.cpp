#include "machineinformation.h"
#include "ui_machineinformation.h"
#include <QMessageBox>

MachineInformation::MachineInformation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MachineInformation)
{
    ui->setupUi(this);

    setWindowTitle("Machine Info");
    setMaximumSize(this->width(), this->height());
    setMinimumSize(this->width(), this->height());

    m_machine = new BMachineControl_64();

    QString info = m_machine->getInfo();
    ui->textEdit->setText(info);
}

MachineInformation::~MachineInformation()
{
    delete m_machine;
    delete ui;
}

void MachineInformation::on_activeBtn_clicked()
{
    bool ret = m_machine->activeKey(ui->lineEdit->text());
    if (ret) {
        QMessageBox::information(nullptr, "info", "Registered successfully !", QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, "error", "Registered failed !", QMessageBox::Ok);
    }
}
