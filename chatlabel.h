#ifndef CHATLABEL_H
#define CHATLABEL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBuffer> //to work with QIODEvice interface for Qbytearrays
#include <QVBoxLayout>
#include <QList>

class ChatLabel : public QWidget
{
    Q_OBJECT



public:

    ChatLabel();
    ~ChatLabel();
    void setLabel();
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
