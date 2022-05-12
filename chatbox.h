#ifndef CHATBOX_H
#define CHATBOX_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <qdebug.h>

/* this class creates top qtextLine (text input) and Qpushbutton at top of main windows
 * to read user data and input via "add" button.*/



class Mainchatbox: public QWidget
{
    Q_OBJECT
public:
    Mainchatbox();
    ~Mainchatbox();
    QLineEdit* inputTextBox; //input textbox reads from user input
    QPushButton* add; //adds our inputed text in to a chat message
    void init();
    void display();
private:


};

#endif // CHATBOX_Hent
