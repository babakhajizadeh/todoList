#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QBuffer> //to work with QIODEvice interface for Qbytearrays
#include "chatlabel.h"

/* this class creates top QtextLine
 * to read user input input .*/



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
};

#endif // CHATBOX_Hent
