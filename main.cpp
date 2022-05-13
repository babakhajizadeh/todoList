#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget mainWindow;
    mainWindow.setWindowTitle("Todo List");
    mainWindow.show();
    return a.exec();
}
