#include "filedisplay.h"

FileDisplay::FileDisplay(char *file_name)
{
    FILE_NAME=file_name;

    QString labelInfo=fileToString();

    window = new QMainWindow;
    QScrollArea *scroll = new QScrollArea(window);
    info = new QLabel(labelInfo,window);
    info->setFont(QFont("",14));
    scroll->setWidget(info);
    window->setCentralWidget(scroll);
    window->setMinimumSize(400,300);
}

QString FileDisplay::fileToString(){
    QFile file(FILE_NAME);
    QString labelInfo;
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);

    while (!in.atEnd()) {
      QString line = in.readLine();
      line+="\n";
      labelInfo+=line;
    }
    file.close();
    return labelInfo;
}

FileDisplay::~FileDisplay()
{
}

