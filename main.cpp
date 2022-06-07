#include "mainwidget.h"

#include <QApplication>

/**
 * @brief In Qt based appliaction main function by defualt is often only responsible in stablishing Qt event Loop mechanism.
 * 
 * Qt event loops is nothing more than a event handler checks for whats new happening under the hood, it is like thinking
 * refreshing program continuously and cheking what has happned , where and who is in charge of it.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget mainWindow;
    mainWindow.setWindowTitle("Todo List");
    mainWindow.show();
    return a.exec();
}
