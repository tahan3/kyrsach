#include "menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(550,300);
    this->setMaximumSize(550,300);
    this->setWindowTitle("system info");

    QVBoxLayout *vbox = new QVBoxLayout();
    vbox->setSpacing(10);
    vbox->setContentsMargins(10,10,10,10);

    list = new QListWidget(this);
    list->setSpacing(1);
    list->addItem("Host name");
    list->addItem("Hardware information");
    list->addItem("CPU info");
    list->addItem("Memory information");
    list->addItem("Swap information");
    list->addItem("Distribution version");
    list->addItem("Kernel version");
    list->addItem("Hard disk information");
    list->addItem("Unit information");
    list->addItem("Free disk space");
    list->addItem("USB information");
    list->addItem("PCI device information");
    list->addItem("System operation time");
    list->addItem("Boot history");
    list->addItem("Kernel modules");
    list->addItem("Socket information");
    list->addItem("Service information");
    list->addItem("Users information");
    list->addItem("Group information");
    list->addItem("Installed packages");
    list->addItem("Firewall information");



    list->resize(300,300);

    setCentralWidget(list);

    connect(list,&QListWidget::doubleClicked,this,&Menu::showInfo);

    //this->setLayout(vbox);
}

void Menu::showInfo(){
    int r=list->currentRow();
    switch(r){
    case HOSTNAME:{
        FindInfo infoFinder;
        infoFinder.createThread("hostname","hostname>hostname");
        FileDisplay *info = new FileDisplay("hostname");
        info->window->show();
    }
        break;
    case HARDWARE_INFO:{
        FindInfo infoFinder;
        infoFinder.createThread("hardware","sudo lshw -short>hardware");
        FileDisplay *info = new FileDisplay("hardware");
        info->window->show();
    }
        break;
    case CPU_INFO:{
        FindInfo infoFinder;
        infoFinder.createThread("cpu","lscpu>cpu");
        FileDisplay *info = new FileDisplay("cpu");
        info->window->show();
    }
        break;
    case MEM_INFO:{
        FindInfo infoFinder;
        infoFinder.createThread("meminfo","less /proc/meminfo>meminfo");
        FileDisplay *info = new FileDisplay("meminfo");
        info->window->show();
    }
        break;
    case SWAP_INFO:{
        FindInfo infoFinder;
        infoFinder.createThread("swapinfo","cat /proc/swaps>swapinfo");
        FileDisplay *info = new FileDisplay("swapinfo");
        info->window->show();
    }
        break;
    case DISTRIB_INFO:{
        FindInfo infoFinder;
        infoFinder.createThread("distribinfo","lsb_release -a>distribinfo");
        FileDisplay *info = new FileDisplay("distribinfo");
        info->window->show();
    }
        break;
    case KERNEL_VERSION:{
        FindInfo infoFinder;
        infoFinder.createThread("kernelversion","uname -a>kernelversion");
        FileDisplay *info = new FileDisplay("kernelversion");
        info->window->show();
    }
        break;
    case HARD_DISK_INFO:{
        FindInfo infoFinder;
        infoFinder.createThread("diskinfo","sudo fdisk -l>diskinfo");
        FileDisplay *info = new FileDisplay("diskinfo");
        info->window->show();
    }
        break;
    case UNIT_INFORMATION:{
        FindInfo infoFinder;
        infoFinder.createThread("unitinfo","lsblk>unitinfo");
        FileDisplay *info = new FileDisplay("unitinfo");
        info->window->show();
    }
        break;
    case DISK_SPACE:{
        FindInfo infoFinder;
        infoFinder.createThread("diskspace","df>diskspace");
        FileDisplay *info = new FileDisplay("diskspace");
        info->window->show();
    }
        break;
    case USB_INFO:{
        FindInfo infoFinder;
        infoFinder.createThread("usbinfo","lsusb>usbinfo");
        FileDisplay *info = new FileDisplay("usbinfo");
        info->window->show();
    }
        break;
    case PCI_INFORMATION:{
        FindInfo infoFinder;
        infoFinder.createThread("pciinfo","lspci>pciinfo");
        FileDisplay *info = new FileDisplay("pciinfo");
        info->window->show();
    }
        break;
    case UPTIME:{
        FindInfo infoFinder;
        infoFinder.createThread("uptime","uptime>uptime");
        FileDisplay *info = new FileDisplay("uptime");
        info->window->show();
    }
        break;
    case BOOT_HISTORY:{
        FindInfo infoFinder;
        infoFinder.createThread("bootstory","last reboot>bootstory");
        FileDisplay *info = new FileDisplay("bootstory");
        info->window->show();
    }
        break;
    case KERNEL_MODULES:{
        FindInfo infoFinder;
        infoFinder.createThread("kernelmodules","lsmod>kernelmodules");
        FileDisplay *info = new FileDisplay("kernelmodules");
        info->window->show();
    }
        break;
    case SOCKET_INFORMATION:{
        FindInfo infoFinder;
        infoFinder.createThread("socket","ss>socket");
        FileDisplay *info = new FileDisplay("socket");
        info->window->show();
    }
        break;
    case SERVICE_INFORMATION:{
        FindInfo infoFinder;
        infoFinder.createThread("serviceinfo","service --status-all>serviceinfo");
        FileDisplay *info = new FileDisplay("serviceinfo");
        info->window->show();
    }
        break;
    case USERS_INFO:{
        FindInfo infoFinder;
        infoFinder.createThread("usersinfo","getent passwd>usersinfo");
        FileDisplay *info = new FileDisplay("usersinfo");
        info->window->show();
    }
        break;
    case GROUP_INFORMATION:{
        FindInfo infoFinder;
        infoFinder.createThread("groupinfo","less /etc/group>groupinfo");
        FileDisplay *info = new FileDisplay("groupinfo");
        info->window->show();
    }
        break;
    case INSTALLED_PACKAGES:{
        FindInfo infoFinder;
        infoFinder.createThread("packagesinfo","dpkg -l>packagesinfo");
        FileDisplay *info = new FileDisplay("packagesinfo");
        info->window->show();
    }
        break;
    case FIREWALL_INFORMATION:{
        FindInfo infoFinder;
        infoFinder.createThread("firewall","sudo iptables -L -n -v>firewall");
        FileDisplay *info = new FileDisplay("firewall");
        info->window->show();
    }
        break;
    }
}

Menu::~Menu()
{
}

