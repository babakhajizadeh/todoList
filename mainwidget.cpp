#include "mainwidget.h"

/**
 * @brief Mainwidget class consructor has major role in creating program's widgets.
 * This class takes responsiblity of creating and initilization of each child via calling respective constructor 
 * and init methods of them by pointers to children class objects and setting up this class as their parrents 
 * in order to have Qt way of memory management .
 * This constructor also sets up connections of children classes slot and signals 
 * as needed for proper functionality of them. and as well as layouts for correct visualization of children widgets
 * on the main widget UI. It creats sobjects of children e.g. addButton, ChatLabel, Mainchatbox and \ref serialize 
 */

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


/**
 * @brief Destroy the Widget:: Widget object
 * Under the hood it has role of calling destrutors of all children widgets in class hierarchy
 */
Widget::~Widget()
{

}

/**
 * @brief Controller method is partially an implement for Model View Controller design
 * by taking care of children widgets.
 * 
 * It impose proper controlled logics in creating and modifying children classes as well as setting up their connections of signals and slots
 * that are explained in details in each respective class documentation. children classes
 * including ChatLabel, Mainchatbox and \ref serialize getting managed via this method 
 * it also handles Edit and Delete requests signals for children classes in charge, e.g.for class \ref serialize 
 * which has responsibility of creating binary data.
 * 
 */

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

/**
 * @brief Plays initial role in deleting ChatLabels.
 * 
 * This method responds Delete button click incident on UI
 * 
 */
void Widget::deleteLabel(ChatLabel* choice, int labelkey)
{
    delete choice;
    qInfo()<< "label with key" << labelkey << "deleted.";
    emit labelObjectDeleteRequest(labelkey); //signal for serializer class
}

/**
 * @brief Plays initial role in editing ChatLabels.
 * 
 * This method responds Edit button click incident on UI
 * 
 */
void Widget::editLabel(ChatLabel* choice, int labelkey)
{
    emit labelObjectEditRequest(choice, labelkey); // signal to serializer
    qInfo()<< "label with key" << labelkey << "wants being edited!.";
    qInfo() << "value:" << choice->getText();
}
