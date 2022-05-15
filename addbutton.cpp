#include "addbutton.h"

addButton::addButton()
{
    qInfo() << "addButton object constructed";
}
addButton::~addButton()
{
    qInfo() << "addButton object destructed";
}

void addButton::init()
{
    add = new QPushButton;

    this->add->setGeometry(370,30,70,50);
    this->add->setText(" ADD ");
    this->add->setStyleSheet("QPushButton {background-color: #A3C1DA}");

    qInfo() << "bottun geometry set!";
    this->add->setParent(this);

    connect (add,
             SIGNAL(released()),
             this,
             SIGNAL(addButtonClicked()));
}

