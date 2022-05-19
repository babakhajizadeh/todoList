#include "mainwidget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(480,620);
    this->setStyleSheet("background-color: grey");

    m_add = new addButton;
    m_add->init();
    m_add->setParent(this);

    m_chatbox = new Mainchatbox;
    m_chatbox->init();
    m_chatbox->setParent(this);

    m_label = new ChatLabel;
    m_label->setParent(this);

    lablesLayout = new QVBoxLayout(this);
    lablesLayout->setSpacing(0);
    lablesLayout->setAlignment(Qt::AlignTop);
    lablesLayout->addWidget(m_label);

    inputBox = new QHBoxLayout(this);
    inputBox->setSpacing(0);
    inputBox->addWidget(m_chatbox);
    inputBox->setAlignment(Qt::AlignTop);
    inputBox->addWidget(m_add);


    lablesLayout->addLayout(inputBox);
    lablesLayout->addWidget(m_label);

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
