#ifndef CHATBOX_H
#define CHATBOX_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QDebug>
#include <QBuffer> //to work with QIODEvice interface for Qbytearrays

/* this class creates top QtextLine
 * to read user input input .*/



class Mainchatbox: public QWidget
{
    Q_OBJECT
public:
    Mainchatbox();
    ~Mainchatbox();
    QLineEdit* inputTextBox; //input textbox reads from user input
    void init();

public slots:
    void getText();

private:
    QByteArray m_input;
    QBuffer m_buffer; //to work with QIODevice interface

};

#endif // CHATBOX_Hent
