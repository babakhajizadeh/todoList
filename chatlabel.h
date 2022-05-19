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
    void init();
    void setLabel();

private:
    QPushButton* del;
    QPushButton* edit;
    QLabel* chatlabel;
    QVector <QLabel*> *labelvect;
    QVBoxLayout* parentLayout;
    QVBoxLayout* buttonLaout;

public slots:
    void getText(QByteArray* input);


private:
    QByteArray* read;
    QBuffer m_buffer;
    QVBoxLayout m_layout;

};

#endif // CHATLABEL_H
