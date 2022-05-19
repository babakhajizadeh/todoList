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
    parentLayout = new QHBoxLayout(this);
    parentLayout->addWidget(add);;
    parentLayout->setSpacing(0);
    add->setFixedHeight(50);
    add->setText(" ADD ");
    add->setStyleSheet("QPushButton {background-color: #A3C1DA}");
    qInfo() << "bottun geometry set.";
    add->setParent(this);
    connect (add,
             SIGNAL(released()),
             this,
             SIGNAL(addButtonClicked()));
    qInfo() << "add button initilized.";
}

