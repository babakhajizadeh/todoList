#ifndef CHATBOX_H
#define CHATBOX_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QBuffer> //to work with QIODEvice interface for Qbytearrays
#include "serialize.h"

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
    void textready(QByteArray* input);

public slots:
    void getText();

private:
    QBuffer m_buffer; //to work with QIODevice interface
    serialize* m_serializer; //instance of class providing serializing job
    int m_keyCounter = 0;
    QByteArray* input;
    QLineEdit* inputTextBox; //input textbox reads from user input
    QHBoxLayout* parentLayout;
};

#endif // CHATBOX_Hent
