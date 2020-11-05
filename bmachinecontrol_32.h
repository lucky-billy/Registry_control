#ifndef BMACHINECONTROL_64_H
#define BMACHINECONTROL_64_H

#include <QAxObject>
#include <QUuid>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSysInfo>
#include <QSettings>
#include <QDebug>
#include <QDesktopWidget>
#include <QFileInfoList>
#include <QDir>
#include <QLibrary>
#include <QTimer>
#include <QHostInfo>
#include <Windows.h>

class BMachineControl_32
{
public:
    BMachineControl_32();

    QString getWMIHWInfo(int type);     // ��ȡ�������к�
    QString getMachineName();           // ��ȡ���������
    QString getIP();                    // ��ȡIP��ַ
    QString getMac();                   // ��ȡ�����MAC��ַ
    QString getCPU();                   // ��ȡ�����CPU��Ϣ
    QString getInfo();                  // ��ȡ�豸��Ϣ


    QString getKey(QString machineinfo, QString ddMMyyyy, int months);  // �����豸��Ϣ�����ڡ���ʹ���·�����key
    bool activeKey(QString key);        // ע��key
    bool initializeReg();               // ��ע�����Ϣ���ʼ��������true, ����ֱ�ӷ���false
    bool judgeDate();                   // �ж������Ƿ񱻹����޸�
    int judgeKey();                     // �ж�key������ʣ��������������Ϊ��
    void refreshDT1();                  // ˢ�� DT1

private:
    const QString kReg = "HKEY_CURRENT_USER\\Software\\Lenovo\\Sirius_Mult";
    const QString kKey = "K";
    const QString kDateTime0 = "DT0";
    const QString kDateTime1 = "DT1";
    const QString kDateTime2 = "DT2";
    const QString kMonths = "M";

    const int kForever = 1000000;
    const QList<int> kValidity = {1, 3, 6, 12, kForever};
};

#endif // BMACHINECONTROL_64_H
