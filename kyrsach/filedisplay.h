#ifndef FILEDISPLAY_H
#define FILEDISPLAY_H

#include <QMainWindow>
#include <QLabel>
#include <fstream>
#include <iostream>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QScrollArea>
#include <QFormLayout>
#include <QScrollArea>
#include <QFile>
#include <QTextStream>

using namespace std;

class FileDisplay
{
public:
    QMainWindow *window;

    FileDisplay(char* FILE_NAME);
    ~FileDisplay();
private:
    QString fileToString();
    char* FILE_NAME;
    QLabel *info;
};
#endif // FILEDISPLAY_H
