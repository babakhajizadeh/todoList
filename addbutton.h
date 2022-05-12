#ifndef ADDBUTTON_H
#define ADDBUTTON_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QMainWindow>

/* this class creates main Qpushbutton
 * to interact with it's Qlineedit that read user inpu .*/



class addButton: public QWidget
{
    Q_OBJECT
public:
    addButton();
    ~addButton();
    QPushButton* add; //main add button
    void init();
private:


};

#endif // ADDBUTTON_H
