#include "chatlabel.h"


ChatLabel::ChatLabel()
{
    qInfo() << "label object constructed";
}

ChatLabel::~ChatLabel()
{
    qInfo() << "label object destructed";
}

void ChatLabel::init(QByteArray* input)
{
    chatlabel = new QLabel;
    chatlabel->setObjectName("label");

    delButton = new QPushButton;
    delButton->setObjectName("delete button");
    editButton = new QPushButton;
    editButton->setObjectName("edit button");

    parentLayout = new QVBoxLayout(this);
    labelLayout = new QHBoxLayout(this);
    buttonLayout = new QVBoxLayout(this);

    chatlabel->setFixedHeight(50);
    delButton->setFixedHeight(24);
    editButton->setFixedHeight(24);

    parentLayout->setSpacing(6);
    labelLayout->setSpacing(5);
    buttonLayout->setSpacing(2);

    delButton->setParent(this);
    delButton->setText("Delete");
    delButton->setStyleSheet("QPushButton {background-color: #A3C1DA}");
    editButton->setParent(this);
    editButton->setText("Edit");
    editButton->setStyleSheet("QPushButton {background-color: #A3C1DA}");
    chatlabel->setParent(this);

    read = new QByteArray;
    m_buffer.setBuffer(read);
    m_buffer.open(QIODeviceBase::WriteOnly);
    m_buffer.write(*input);
    m_buffer.close();
    qInfo() << "label slot connected.";
    qInfo() << "label have red:" << *read;

    /*some sort of layouting*/
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(delButton);
    // bottuns added to button layout

    labelLayout->addWidget(chatlabel,6);
    labelLayout->addLayout(buttonLayout,2);

    parentLayout->addLayout(labelLayout);
    parentLayout->setAlignment(Qt::AlignTop);

    setStyleSheet("QLabel { background-color: #f2f1cb }");
    qInfo() << "Label geometry set!";
    chatlabel->setText(*read);

    connect (delButton,
             SIGNAL(released()),
             this,
             SIGNAL(delButtonClicked()));
    connect (editButton,
             SIGNAL(released()),
             this,
             SIGNAL(editButtonClicked()));
}
