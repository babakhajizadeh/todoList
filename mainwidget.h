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
