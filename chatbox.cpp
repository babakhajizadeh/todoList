#include "chatbox.h"
class Widget;

Mainchatbox::Mainchatbox()
{
    qInfo() << "mainchatbox object constructed";
}
Mainchatbox::~Mainchatbox()
{
    qInfo() << "mainchatbox object destructed";
}

void Mainchatbox::init()
{

    inputTextBox = new QLineEdit;
    QObject::connect(inputTextBox,
             SIGNAL(returnPressed()),
             this,
             SIGNAL(RetunKeyPressed()));

    parentLayout = new QHBoxLayout(this);
    parentLayout->addWidget(inputTextBox);
    parentLayout->setSpacing(0);

    inputTextBox->setFixedHeight(50);
    inputTextBox->setParent(this);


    this->setStyleSheet("QLineEdit { background-color: yellow }");

    inputTextBox->setStyleSheet("QLineEdit { background-color: white }");
    qInfo() << "text box geometry set!";
    this->inputTextBox->setParent(this);
    this->inputTextBox->setPlaceholderText("Click to write");

}

void Mainchatbox::getText()
{
    if(!editMode){
        input = new QByteArray;
        m_buffer.setBuffer(input);
        qInfo() << "mainchat box slot connected";
        m_keyCounter++;
        m_buffer.open(QIODeviceBase::WriteOnly);
        m_buffer.write(this->inputTextBox->text().toUtf8()); //reads user input from ui
        m_buffer.close();
        inputTextBox->clear();
        emit textready(input,m_keyCounter);
    }
    else
    {
        input = new QByteArray;
        m_buffer.setBuffer(input);
        qInfo() << "mainchat box slot connected";
        m_buffer.open(QIODeviceBase::WriteOnly);
        m_buffer.write(this->inputTextBox->text().toUtf8()); //reads user input from ui
        m_buffer.close();
        inputTextBox->clear();

        underEdit->edit(input);
        emit editready(underEdit,underEditKey);
        underEdit->setDisabled(false);
    }
}

void Mainchatbox::editRequestHandler(ChatLabel* choice, int labelkey)
{   //copies label text to chatbox for edit
    underEdit = choice;
    underEditKey = labelkey;
    qInfo() << "mainchatbox slot for label edit trigerred";
    qInfo() << "value:" << underEdit->getText();
    underEdit->setDisabled(true);
    this->inputTextBox->setText(underEdit->getText());
    editMode = true;
}
