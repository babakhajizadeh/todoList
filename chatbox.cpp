#include "chatbox.h"

Mainchatbox::Mainchatbox()
{
    qInfo() << "mainchatbox object constructed";
}
Mainchatbox::~Mainchatbox()
{
    qInfo() << "mainchatbox object destructed";
}

void Mainchatbox::init()
{
    add = new QPushButton;

    inputTextBox = new QLineEdit;

    this->inputTextBox->setGeometry(25,30,130,25);
    qInfo() << "text box geometry set!";
    this->add->setGeometry(140,30,50,25);
    qInfo() << "bottun geometry set!";
    this->inputTextBox->setParent(this);
    this->add->setParent(this);
}

void Mainchatbox::display()
{
    this->add->show();
    this->add->show();

}

