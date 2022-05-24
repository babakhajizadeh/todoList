#include "mainwidget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(480);
    setMinimumHeight(620);

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

    m_serializer = new serialize;
    QObject::connect(m_serializer,
                     &serialize::jsonReady,
                     this,
                     &Widget::controller);
    m_serializer->init();
    m_serializer->setParent(this);



    QObject::connect(m_add,
                     &addButton::addButtonClicked,
                     m_chatbox,
                     &Mainchatbox::getText);

    QObject::connect(m_chatbox,
                     &Mainchatbox::RetunKeyPressed,
                     m_chatbox,
                     &Mainchatbox::getText);

    QObject::connect(m_chatbox,
                     &Mainchatbox::textready,
                     this,
                     &Widget::controller);

    QObject::connect(this,
                    &Widget::chatLabelObjectConstructed,
                    m_serializer,
                    &serialize::serializer,Qt::UniqueConnection);

    QObject::connect(m_chatbox,
                    &Mainchatbox::editready,
                    m_serializer,
                    &serialize::edit,Qt::UniqueConnection);

    QObject::connect(this,
                    &Widget::labelObjectDeleteRequest,
                    m_serializer,
                    &serialize::remove,Qt::UniqueConnection);

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

    QObject::connect(this,
                     &Widget::labelObjectEditRequest,
                     m_chatbox,
                     &Mainchatbox::editRequestHandler,Qt::UniqueConnection);
    emit chatLabelObjectConstructed(m_label,keycounter);
}

void Widget::deleteLabel(ChatLabel* choice, int labelkey)
{
    delete choice;
    qInfo()<< "label with key" << labelkey << "deleted.";
    emit labelObjectDeleteRequest(labelkey); //signal for serializer class
}

void Widget::editLabel(ChatLabel* choice, int labelkey)
{
    emit labelObjectEditRequest(choice, labelkey); // signal to serializer
    qInfo()<< "label with key" << labelkey << "wants being edited!.";
    qInfo() << "value:" << choice->getText();
}
