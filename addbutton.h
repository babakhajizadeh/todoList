#ifndef ADDBUTTON_H
#define ADDBUTTON_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QHBoxLayout>  >

/* this class provides 'add' and 'edit' Qpushbuttons
 * to interact with their Qlineedit of each read user input.*/



class addButton: public QWidget
{
    Q_OBJECT
public:
    addButton();
    ~addButton();
    void init();
    QPushButton* add; //for either add or edit buttons
    QHBoxLayout* parentLayout;
private:


signals:
    void addButtonClicked();

};

#endif // ADDBUTTON_H
