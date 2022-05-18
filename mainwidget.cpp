#include "mainwidget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(480, 620);
    this->setStyleSheet("background-color: grey");

    m_add = new addButton;
    m_add->init();
    m_add->setParent(this);

    m_chatbox = new Mainchatbox;
    m_chatbox->init();
    m_chatbox->setParent(this);

    QObject::connect(m_add,
                     &addButton::addButtonClicked,
                     m_chatbox,
                     &Mainchatbox::getText);
}

Widget::~Widget()
{

}
