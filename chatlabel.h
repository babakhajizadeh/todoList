#ifndef CHATLABEL_H
#define CHATLABEL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBuffer> //to work with QIODEvice interface for Qbytearrays
#include <QVBoxLayout>
#include <QList>
#include <QDebug>
/**
 * @brief This class has major responsiblity in creating todo tasks as known as Chat Labels.
 * 
 * In else wheres in this program, what's so called Chat Labels are in fact todo list tasks
 * and their corresponding widgets on UI, these widgets creations get triggered by add button 
 * which is defined in class addButton and reads it's data from class Mainchatbox.
 * this class is able to intract with both of those classes for unlimited times.
 * 
 */

class ChatLabel : public QWidget
{
    Q_OBJECT

public:

    ChatLabel();
    ~ChatLabel();
    QString getText();
    void edit(QByteArray* newtext);

private:
    QPushButton* delButton;
    QPushButton* editButton;
    QLabel* chatlabel;
    QVBoxLayout* parentLayout; //provides vertical layout for main widget
    QHBoxLayout* labelLayout;  //each label and respecting buttons
    QVBoxLayout* buttonLayout; //initial add and delete buttons layout


signals:
    void delButtonClicked(ChatLabel*,int);
    void editButtonClicked(ChatLabel*, int);


public slots:
    void init(QByteArray* input, int labelkey);
    void deleteSignalEmitter();
    void editSignalEmiter();


private:
    QByteArray* read;
    QBuffer m_buffer;
    QVBoxLayout m_layout;
    int m_key = 0;
};

#endif // CHATLABEL_H
