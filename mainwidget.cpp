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

    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setAlignment(Qt::AlignTop);

    inputBox = new QHBoxLayout(this);
    inputBox->setSpacing(0);
    inputBox->addWidget(m_chatbox);
    inputBox->setAlignment(Qt::AlignTop);
    inputBox->addWidget(m_add);

    mainLayout->addLayout(inputBox);
//

    QObject::connect(m_add,
                     &addButton::addButtonClicked,
                     m_chatbox,
                     &Mainchatbox::getText);

    QObject::connect(m_chatbox,
                     &Mainchatbox::textready,
                     this,
                     &Widget::controller);

}



Widget::~Widget()
{

}

void Widget::controller(QByteArray *input, int keycounter)
{
    qInfo () << "mainwidget slot connected.";

    m_label = new ChatLabel;
    m_label->setParent(this);
    m_label->init(input, keycounter);
    mainLayout->addWidget(m_label); //includes child layouts of labels
    mainLayout->setAlignment(Qt::AlignTop);
    QObject::connect(m_label,
                     &ChatLabel::delButtonClicked,
                     this,
                     &Widget::deleteLabel);
    QObject::connect(m_label,
                     &ChatLabel::editButtonClicked,
                     this,
                     &Widget::editLabel);
}

void Widget::deleteLabel(ChatLabel* choice, int labelkey)
{
    delete choice;
    qInfo()<< "label with key" << labelkey << "deleted.";
    emit labelObjectDeleted(labelkey); //signal for serializer class
}

void Widget::editLabel(ChatLabel* choice, int labelkey)
{
    emit labelObjectEdited(choice, labelkey); // signal to serializer
    qInfo()<< "label with key" << labelkey << "wants being edit!.";
}
