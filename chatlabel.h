#ifndef CHATLABEL_H
#define CHATLABEL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBuffer> //to work with QIODEvice interface for Qbytearrays

class ChatLabel : public QWidget
{
    Q_OBJECT



public:
    QPushButton* del;
    QPushButton* edit;
    QLabel* chatlabel;
    ChatLabel();
    ~ChatLabel();
    void init();


public slots:
    void getText(QByteArray* input);


private:
    QByteArray* read;
    QBuffer m_buffer;

};

#endif // CHATLABEL_H
