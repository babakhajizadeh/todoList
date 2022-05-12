#ifndef CHATBOX_H
#define CHATBOX_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QMainWindow>

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
private:


};

#endif // CHATBOX_Hent
