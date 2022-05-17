#ifndef ADDBUTTON_H
#define ADDBUTTON_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QMainWindow>

/* this class provides 'add' and 'edit' Qpushbuttons
 * to interact with their Qlineedit of each read user input.*/



class addButton: public QWidget
{
    Q_OBJECT
public:
    addButton();
    ~addButton();
    void init();
private:
    QPushButton* add; //for either add or edit buttons


signals:
    void addButtonClicked();

};

#endif // ADDBUTTON_H
