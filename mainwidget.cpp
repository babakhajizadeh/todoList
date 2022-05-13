#include "mainwidget.h"
#include "./ui_mainwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    this->setFixedSize(480, 620);
    this->setStyleSheet("background-color: grey");
    this->ui->setupUi(this);

    m_add = new addButton;
    m_add->init();
    m_add->setParent(this);

    m_chatbox = new Mainchatbox;
    m_chatbox->init();
    m_chatbox->setParent(this);
}

Widget::~Widget()
{
    delete ui;
}

