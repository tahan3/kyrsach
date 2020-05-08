#ifndef MENU_H
#define MENU_H

#define HOSTNAME 0
#define HARDWARE_INFO 1
#define CPU_INFO 2
#define MEM_INFO 3
#define SWAP_INFO 4
#define DISTRIB_INFO 5
#define KERNEL_VERSION 6
#define HARD_DISK_INFO 7
#define UNIT_INFORMATION 8
#define DISK_SPACE 9
#define USB_INFO 10
#define PCI_INFORMATION 11
#define UPTIME 12
#define BOOT_HISTORY 13
#define KERNEL_MODULES 14
#define SOCKET_INFORMATION 15
#define SERVICE_INFORMATION 16
#define USERS_INFO 17
#define GROUP_INFORMATION 18
#define INSTALLED_PACKAGES 19
#define FIREWALL_INFORMATION 20

#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <threads.h>
#include <filedisplay.h>

class Menu : public QMainWindow
{
    Q_OBJECT
private:
    QPushButton *hostnameBtn;
    QListWidget *list;
private slots:
    void showInfo();
public:
    Menu(QWidget *parent = nullptr);
    ~Menu();
};
#endif // MENU_H
