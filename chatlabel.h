#ifndef CHATLABEL_H
#define CHATLABEL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QBuffer> //to work with QIODEvice interface for Qbytearrays
#include <QVBoxLayout>

class ChatLabel : public QWidget
{
    Q_OBJECT



public:
    QPushButton* del;
    QPushButton* edit;
    QLabel* chatlabel;
    QHBoxLayout* parentLayout;
    QVBoxLayout* buttonLaout;

    ChatLabel();
    ~ChatLabel();
    void init();


public slots:
    void getText(QByteArray* input);


private:
    QByteArray* read;
    QBuffer m_buffer;
    QVBoxLayout m_layout;

};

#endif // CHATLABEL_H
