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

    labelvect = new QVector<QLabel*>;
    parentLayout = new QVBoxLayout(this);
    parentLayout->setSpacing(6);
}

void ChatLabel::setLabel()
{
    chatlabel = new QLabel;
    chatlabel->setAlignment(Qt::AlignTop);
    parentLayout->addWidget(chatlabel);
    chatlabel->setFixedHeight(50);
    chatlabel->setParent(this);
    setStyleSheet("QLabel { background-color: #bfe2ff }");
    qInfo() << "Label geometry set!";
    chatlabel->setText(*read);
    chatlabel->setParent(this);
    labelvect->push_back(chatlabel);
    qInfo() << "totall labels in vecor:" << labelvect->count();
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
    setLabel();
}
