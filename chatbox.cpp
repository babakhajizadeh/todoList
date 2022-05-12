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

    inputTextBox = new QLineEdit;

    this->inputTextBox->setGeometry(30,30,320,50);
    setStyleSheet("QLineEdit { background-color: white }");
    qInfo() << "text box geometry set!";
    qInfo() << "bottun geometry set!";
    this->inputTextBox->setParent(this);
}
