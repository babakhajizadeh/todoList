#include "chatlabel.h"


ChatLabel::ChatLabel()
{
    qInfo() << "label object constructed";
}

ChatLabel::~ChatLabel()
{
    qInfo() << "label object destructed";
}

void ChatLabel::init()
{

    chatlabel = new QLabel;
    chatlabel->setAlignment(Qt::AlignTop);

    parentLayout = new QHBoxLayout(this);
    parentLayout->addWidget(chatlabel);
    parentLayout->setSpacing(0);
    parentLayout->setSpacing(0);

    chatlabel->setFixedHeight(100);
    chatlabel->setParent(this);


    setStyleSheet("QLabel { background-color: #bfe2ff }");
    qInfo() << "Label geometry set!";
    chatlabel->setText(*read);
    chatlabel->setParent(this);
    this->show();

}

void ChatLabel::getText(QByteArray* input)
{
    read = new QByteArray;
    m_buffer.setBuffer(read);
    m_buffer.open(QIODeviceBase::WriteOnly);
    m_buffer.write(*input);
    m_buffer.close();
    qInfo() << "label slot connected.";
    qInfo() << "label have red:" << *read;
    init();
}
