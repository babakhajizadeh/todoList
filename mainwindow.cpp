#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setStyleSheet("background-color:grey;");
    this->setFixedSize(480, 620);

    m_chatbox = new Mainchatbox;    //this makes a Qpushbutton and Qtextline
                                    //at top of widgets to read user input
                                    //then initialize its geometry
//    m_chatbox->setParent(this);     //memory management
    m_chatbox->init();
    m_chatbox->display();
    m_chatbox->show();               //it shows while setParent() line in comment



    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}

