#ifndef MACHINEINFORMATION_H
#define MACHINEINFORMATION_H

#include <QMainWindow>
#include <bmachinecontrol_64.h>

namespace Ui {
class MachineInformation;
}

class MachineInformation : public QMainWindow
{
    Q_OBJECT

public:
    explicit MachineInformation(QWidget *parent = nullptr);
    ~MachineInformation();

private slots:
    void on_activeBtn_clicked();

private:
    Ui::MachineInformation *ui;
    BMachineControl_64 *m_machine;
};

#endif // MACHINEINFORMATION_H
