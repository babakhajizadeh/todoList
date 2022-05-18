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

    m_label = new ChatLabel;
//    m_label->setParent(this); must have layout first

    QObject::connect(m_add,
                     &addButton::addButtonClicked,
                     m_chatbox,
                     &Mainchatbox::getText);

    QObject::connect(m_chatbox,
                     &Mainchatbox::textready,
                     m_label,
                     &ChatLabel::getText);
}

Widget::~Widget()
{

}
