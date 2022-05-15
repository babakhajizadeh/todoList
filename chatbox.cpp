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

    inputTextBox->setGeometry(30,30,320,50);
    setStyleSheet("QLineEdit { background-color: white }");
    qInfo() << "text box geometry set!";
    this->inputTextBox->setParent(this);
    this->inputTextBox->setPlaceholderText("Click to write");


}

void Mainchatbox::getText()
{
    m_buffer.setBuffer(&m_input);
    qInfo() << "mainchat box slot connected";
    m_buffer.open(QIODeviceBase::WriteOnly);
    m_buffer.write(this->inputTextBox->text().toUtf8());
    m_buffer.close();
    qInfo() << m_input;
}

