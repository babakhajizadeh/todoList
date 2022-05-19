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

private slots:

private:
    QVBoxLayout *lablesLayout;
    QHBoxLayout *inputBox;
    QWidget* displayWidget;
    Mainchatbox* m_chatbox; //main text field to read user input via QLineEdit
    addButton* m_add;       //main add button
    ChatLabel* m_label;     //labels
};
#endif // WIDGET_H
