#include "chatlabel.h"

/**
 * @brief Construct a new Chat Label:: Chat Label object.
 * 
 * Also notifies it's success by a message to stderr.
 * 
 */
ChatLabel::ChatLabel()
{
    qInfo() << "label object constructed";
}

/**
 * @brief Destroy the Chat Label:: Chat Label object
 * 
 * Also notifies it's success by a message to stderr.
 *
 */
ChatLabel::~ChatLabel()
{
    qInfo() << "label object destructed";
}

/**
 * @brief method getText() returns string value of each chat labels.
 * 
 * in the class \ref serialize it is needed to read a ChatLabel instance string value which accomplished 
 * by methods serialize::buildMap and serialize::edit and they inlinely call this method, This must
 * NOT TO BE CONFUSED by same method name in class Mainchatbox,
 * 
 * @return QString 
 */
QString ChatLabel::getText()
{
    return chatlabel->text();
}


/**
 * @brief method for edit ChatLabel instance's string values
 * 
 * Once Edit button provided by class Mainchatbox triggered (released), eventually this will be called as a method to 
 * modify string value followed by editButtonClicked() signal which notifies class \ref serialize and Mainchatbox of 
 * the ongoing edit incident.
 * 
 * @param newtext 
 */
void ChatLabel::edit(QByteArray *newtext)
{
    this->chatlabel->clear();
    this->chatlabel->setText(*newtext);
}

/**
 * @brief Method for early initialization of class ChatLabel and it's components.
 * 
 * which is constructs encapsulated objects 
 * including push buttons Delete and Edit as well as a Label for displying texts and Ui Layouts 
 * which organize all corresponding widgets on UI
 *   
 * 
 * @param input 
 * @param labelkey 
 */
void ChatLabel::init(QByteArray* input, int labelkey)
{
    chatlabel = new QLabel;
    m_key = labelkey;
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
    m_buffer.open(QIODevice::WriteOnly);
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
    delete read;

    connect (delButton,
             SIGNAL(released()),
             this,
             SLOT(deleteSignalEmitter()));

    connect (editButton,
             SIGNAL(released()),
             this,
             SLOT(editSignalEmiter()));
}

/**
 * @brief This method emits delButtonClicked() signal.
 * 
 * It then activates slot Widget::deleteLabel slot of main widget and eventually when 
 * ChatLabel object deleted it emits Widget::labelObjectDeleteRequest signal to notify slot of serialize::remove
 * which takes reponsiblity of removing ChatLabel also from binary file.
 * 
 */

void ChatLabel::deleteSignalEmitter()
{
    emit delButtonClicked(this, m_key);
}

/**
 * @brief This method emit editButtonClicked() signal once end user click on Edit button on UI.
 * and that signal trigers Widget::editLabel slot in main widget where another signal of
 * Widget::labelObjectEditRequest emits to notify both classes of Mainchatbox via
 * Mainchatbox::editRequestHandler slot and \ref serialize via
 * serialize::edit slot both of them take part in editing the chat label either from
 * class instance and binary file all connections here handled by 
 * method Widget::controller in  mian widget 
 * 
 */
void ChatLabel::editSignalEmiter()
{

    emit editButtonClicked(this, m_key);
}

