#include "menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(550,300);
    this->setMaximumSize(550,300);

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
        createThread("hostname.txt","hostname>hostname.txt");
        FileDisplay *info = new FileDisplay("hostname.txt");
        info->window->show();
    }
        break;
    case HARDWARE_INFO:{
        createThread("hardware.txt","sudo lshw -short>hardware.txt");
        FileDisplay *info = new FileDisplay("hardware.txt");
        info->window->show();
    }
        break;
    case CPU_INFO:{
        createThread("cpu.txt","lscpu>cpu.txt");
        FileDisplay *info = new FileDisplay("cpu.txt");
        info->window->show();
    }
        break;
    case MEM_INFO:{
        createThread("meminfo.txt","less /proc/meminfo>meminfo.txt");
        FileDisplay *info = new FileDisplay("meminfo.txt");
        info->window->show();
    }
        break;
    case SWAP_INFO:{
        createThread("swapinfo.txt","cat /proc/swaps>swapinfo.txt");
        FileDisplay *info = new FileDisplay("swapinfo.txt");
        info->window->show();
    }
        break;
    case DISTRIB_INFO:{
        createThread("distribinfo.txt","lsb_release -a>distribinfo.txt");
        FileDisplay *info = new FileDisplay("distribinfo.txt");
        info->window->show();
    }
        break;
    case KERNEL_VERSION:{
        createThread("kernelversion.txt","uname -a>kernelversion.txt");
        FileDisplay *info = new FileDisplay("kernelversion.txt");
        info->window->show();
    }
        break;
    case HARD_DISK_INFO:{
        createThread("diskinfo.txt","sudo fdisk -l>diskinfo.txt");
        FileDisplay *info = new FileDisplay("diskinfo.txt");
        info->window->show();
    }
        break;
    case UNIT_INFORMATION:{
        createThread("unitinfo.txt","lsblk>unitinfo.txt");
        FileDisplay *info = new FileDisplay("unitinfo.txt");
        info->window->show();
    }
        break;
    case DISK_SPACE:{
        createThread("diskspace.txt","df>diskspace.txt");
        FileDisplay *info = new FileDisplay("diskspace.txt");
        info->window->show();
    }
        break;
    case USB_INFO:{
        createThread("usbinfo.txt","lsusb>usbinfo.txt");
        FileDisplay *info = new FileDisplay("usbinfo.txt");
        info->window->show();
    }
        break;
    case PCI_INFORMATION:{
        createThread("pciinfo.txt","lspci>pciinfo.txt");
        FileDisplay *info = new FileDisplay("pciinfo.txt");
        info->window->show();
    }
        break;
    case UPTIME:{
        createThread("uptime.txt","uptime>uptime.txt");
        FileDisplay *info = new FileDisplay("uptime.txt");
        info->window->show();
    }
        break;
    case BOOT_HISTORY:{
        createThread("bootstory.txt","last reboot>bootstory.txt");
        FileDisplay *info = new FileDisplay("bootstory.txt");
        info->window->show();
    }
        break;
    case KERNEL_MODULES:{
        createThread("kernelmodules.txt","lsmod>kernelmodules.txt");
        FileDisplay *info = new FileDisplay("kernelmodules.txt");
        info->window->show();
    }
        break;
    case SOCKET_INFORMATION:{
        createThread("socket.txt","ss>socket.txt");
        FileDisplay *info = new FileDisplay("socket.txt");
        info->window->show();
    }
        break;
    case SERVICE_INFORMATION:{
        createThread("serviceinfo.txt","service --status-all>serviceinfo.txt");
        FileDisplay *info = new FileDisplay("serviceinfo.txt");
        info->window->show();
    }
        break;
    case USERS_INFO:{
        createThread("usersinfo.txt","getent passwd>usersinfo.txt");
        FileDisplay *info = new FileDisplay("usersinfo.txt");
        info->window->show();
    }
        break;
    case GROUP_INFORMATION:{
        createThread("groupinfo.txt","less /etc/group>groupinfo.txt");
        FileDisplay *info = new FileDisplay("groupinfo.txt");
        info->window->show();
    }
        break;
    case INSTALLED_PACKAGES:{
        createThread("packagesinfo.txt","dpkg -l>packagesinfo.txt");
        FileDisplay *info = new FileDisplay("packagesinfo.txt");
        info->window->show();
    }
        break;
    case FIREWALL_INFORMATION:{
        createThread("firewall.txt","sudo iptables -L -n -v>firewall.txt");
        FileDisplay *info = new FileDisplay("firewall.txt");
        info->window->show();
    }
        break;
    }
}

Menu::~Menu()
{
}

