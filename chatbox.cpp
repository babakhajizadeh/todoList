#include "chatbox.h"
class Widget;

/**
 * @brief Construct a new Mainchatbox:: Mainchatbox object
 * 
 * Also notifies it's success by a message to stderr.
 * 
 */

Mainchatbox::Mainchatbox()
{
    qInfo() << "mainchatbox object constructed";
}

/**
 * @brief Destroy the Mainchatbox:: Mainchatbox object
 * 
 * Also notifies it's success by a message to stderr.
 * 
 */
Mainchatbox::~Mainchatbox()
{
    qInfo() << "mainchatbox object destructed";
}

/**
 * @brief This method once called by main widget right after construction take initilization job.
 *  
 * It creats a line edit widget and sets up it's layout for UI as well as it's class hierarchy.
 * 
 */
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

/**
 * @brief This is a key method and slot which has responsiblity of working with several other
 * slots and signals to privide them with string value of user input when it is needed.
 * 
 * 
 * This class in order to have ChatLabel class instances get created or modified which actually are are todo tasks,
 * It manages to work as explained below; \n 
 * At a fresh start it responds to addButton::addButtonClicked, 
 * signal from addButton class and provides text and key to by emitting Mainchatbox::textready signal to 
 * main widget's Widget::controller slot which is responsible in creating chat labels. as well,
 * Mainchatbox::editRequestHandler slot also once triggeered by Widget::labelObjectEditRequest signal uses
 * this method to get text value and unique key for each. And once edit is done this slot 
 * emits Mainchatbox::editready signal which triggers serialize::edit method of class \ref serialize, letting the changes 
 * to be saved in to a binary file
 * 
 */
void Mainchatbox::getText()
{
    if(!editMode){
        if(QFileInfo::exists(m_fileName) && notyetchecked) //cheks wheter any record exist.
        {
            m_serializedFile = new QFile(m_fileName);
            m_serializedFile->open(QIODevice::ReadOnly);
            m_streamIn.setVersion(QDataStream::Qt_4_0);
            m_streamIn.setDevice(m_serializedFile);
            m_streamIn >> m_jsonobject;
            m_serializedFile->close(); //flush every thing to file
            foreach(const QString& olderkeys, m_jsonobject.keys())
            {
                m_keyCounter++;
            }
            notyetchecked = false;
        }
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


/**
 * @brief This method takes a small role in editing procedure.
 * Once Edit button clicked on UI it emits Widget::labelObjectEditRequest signal which triggres this slot
 * it is responsible in copying value of a chat label to Mainchatbox class for editing.
 * 
 * @param choice A pointer to ChatLabel class object
 * @param labelkey It's correspinding key
 */
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
