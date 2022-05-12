#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chatbox.h"


class Mainchatbox;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setSize();


    ~MainWindow();
private:
    Ui::MainWindow *ui;
    Mainchatbox* m_chatbox; //test

};
#endif // MAINWINDOW_H
