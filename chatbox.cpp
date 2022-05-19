#include "chatbox.h"
class Widget;

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
    parentLayout = new QHBoxLayout(this);
    parentLayout->addWidget(inputTextBox);
    parentLayout->setSpacing(0);

    inputTextBox->setFixedHeight(50);
    inputTextBox->setParent(this);


    this->setStyleSheet("QLineEdit { background-color: yellow }");

    inputTextBox->setStyleSheet("QLineEdit { background-color: white }");
    qInfo() << "text box geometry set!";
    this->inputTextBox->setParent(this);
    this->inputTextBox->setPlaceholderText("Click to write");
    m_serializer = new serialize;
    m_serializer->init();
    m_serializer->setParent(this);
    qInfo() << "serializer object constructed";

}

void Mainchatbox::getText()
{
    input = new QByteArray;

    m_buffer.setBuffer(input);
    qInfo() << "mainchat box slot connected";
    m_keyCounter++;
    m_buffer.open(QIODeviceBase::WriteOnly);
    m_buffer.write(this->inputTextBox->text().toUtf8()); //reads user input from ui
    m_buffer.close();
    inputTextBox->clear();
    emit textready(input);
    m_serializer->writeFile(input, m_keyCounter);
}
