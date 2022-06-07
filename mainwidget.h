#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "chatbox.h"
#include "addbutton.h"
#include "serialize.h"
#include "chatlabel.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

/**
 * @brief Main Wigget class is a simulation for Qt's standard QMainWindow with some small differencies.
 * 
 * Actually normal widget class used instead of Qt's Mainwindow class as features in QMainwindow were not needed.
 * This class is as well responsible of establishing Main window of the program containing all widgets and layouts.
 * And under the hood this class is grand parent class for all others class below so it can take care of memory management in Qt way,
 * this class also partially implements Model View Controller design pattern by defining a \ref controller() method taking care of children widget's
 * affairs including their initiliziation calls via respective init method of each. 
 * 
 */


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    void labelObjectDeleteRequest(int labelkey);
    void labelObjectEditRequest(ChatLabel* choice, int labelkey);
    void chatLabelObjectConstructed(ChatLabel* m_chatLabel, int key);


public slots:
    void controller(QByteArray* input,int keycouter);
    void deleteLabel(ChatLabel* choice, int labelkey);
    void editLabel(ChatLabel* choice, int labelkey);

protected slots:


private:
    serialize* m_serializer;
    QVBoxLayout *mainLayout;
    QHBoxLayout *inputBox;
    QWidget* displayWidget;
    Mainchatbox* m_chatbox; //main text field to read user input via QLineEdit
    addButton* m_add;       //main add button
    ChatLabel* m_label;     //labels
    QMap <QString,ChatLabel> *lebelsParentClassList;

};
#endif // WIDGET_H
