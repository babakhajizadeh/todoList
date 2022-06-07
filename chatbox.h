#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QBuffer> //to work with QIODEvice interface for Qbytearrays
#include "chatlabel.h"
#include <QFileInfo>
#include <QIODevice>
#include <QJsonObject>
#include <QFile>

/**
 * @brief This class is responsible in creating input text box and it's management,
 * 
 * It reads End User input from UI widget and has public member slots to intract with 
 * with edit requests by Edit button provided by class ChatLabel via editRequestHandler() slot as well as 
 * getText() slot which privides string value of inputed text It also notifies class  \ref serialize 
 * via signal Mainchatbox::editready about edit accomplishment, so serializer class can proceed saving new changes
 * This class as well informs main widget Widget::controller slot via signal Mainchatbox::textready()
 * so the controller method of main widget reponds with creating new instance of class ChatLabel.
 * Additionally this class also monitors whether Return key is pressed as the same way it monitors if addButton::addButtonClicked
 * to know when text input must be considered accomplished.
 * 
 */



class Mainchatbox: public QWidget
{
    Q_OBJECT
public:
    Mainchatbox();
    ~Mainchatbox();
    void init();


signals:
    void textready(QByteArray* input,int keycouter);
    void editready(ChatLabel* underEdit, int underEditkey);
    void RetunKeyPressed();

public slots:
    void getText();
    void editRequestHandler(ChatLabel* ignore, int labelkey);

private:
    QBuffer m_buffer; //to work with QIODevice interface
    int m_keyCounter = 0;
    QByteArray* input;
    QLineEdit* inputTextBox; //input textbox reads from user input
    QHBoxLayout* parentLayout;
    bool editMode = false;
    ChatLabel* underEdit;
    int underEditKey = 0;
    QJsonObject m_jsonobject; //json object of whole tasks
    QString m_fileName = "tasks.txt";       //binary file name                  //class chatlabel works with type int
    QDataStream m_streamOut;     //serializes data into binary
    QDataStream m_streamIn;
    QVariantMap m_vmap;         //helps write Qmap to json
    QFile* m_serializedFile;  //binaty file
    bool notyetchecked = true;
};

#endif // CHATBOX_Hent
