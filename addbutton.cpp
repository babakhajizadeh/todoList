#include "addbutton.h"

/**
 * @brief Construct a new add Button::add Button object.
 * 
 * Also notifies it's success by a message to stderr.
 */
addButton::addButton()
{
    qInfo() << "addButton object constructed";
}

/**
 * @brief Destroy the add Button::add Button object
 * 
 * Also notifies it's success by a message to stderr.
 * 
 */
addButton::~addButton()
{
    qInfo() << "addButton object destructed";
}

/**
 * @brief This init method construct a push button and sets it layout and manages signals.
 * 
 * This is a simple init method does nothing more rather than some self-explanatory
   initilization
 * 
 */

void addButton::init()
{
    add = new QPushButton;
    add->setAutoDefault(true);
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

