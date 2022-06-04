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

class BMachineControl_64
{
public:
    BMachineControl_64();

    QString getWMIHWInfo(int type);     // 获取各类序列号
    QString getMachineName();           // 获取计算机名称
    QString getIP();                    // 获取IP地址
    QString getMac();                   // 获取计算机MAC地址
    QString getCPU();                   // 获取计算机CPU信息
    QString getInfo();                  // 获取设备信息

    QString getKey(QString machineInfo, QString ddMMyyyy, int months);  // 根据设备信息、日期、可使用月份生成key
    bool activeKey(QString key);        // 向注册表写入信息

    bool judgeRegistry();               // 判断是否有注册表信息
    bool judgeDate();                   // 判断日期是否被故意修改
    int judgeKey();                     // 判断key，返回剩余天数，过期则为负
    void refreshDT1();                  // 刷新最后一次打开软件的时间

private:
//    const QString kReg = "HKEY_CURRENT_USER\\Software\\Lenovo\\Sirius_Pro";     // 注册表路径
    const QString kReg = "HKEY_LOCAL_MACHINE\\Software\\Lenovo\\Sirius_Pro";    // 注册表路径（MACHINE 需要管理员权限）
    const QString kKey = "K";           // 密钥
    const QString kDateTime0 = "DT0";   // 软件注册的时间
    const QString kDateTime1 = "DT1";   // 最后一次打开软件的时间
    const QString kDateTime2 = "DT2";   // 第一次打开软件的时间
    const QString kMonths = "M";        // 可使用软件的月数

    const int kForever = 1000000;
    const QList<int> kValidity = {1, 3, 6, 12, kForever};
};

#endif // BMACHINECONTROL_64_H
