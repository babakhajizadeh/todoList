#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(480, 620);
    this->setStyleSheet("background-color: grey");


    m_chatbox = new Mainchatbox;    //this makes a Qtextline at top of widgets to read user input
    m_chatbox->init();              //this sets it's geometry
    m_chatbox->setParent(this);     //sets parrent for memory management

    m_add = new addButton;    //this makes a Qpushbutton called "add" for upper Qtextline that reads suer input
    m_add->init();              //this sets it's geometry
    m_add->setParent(this);   //sets parrent for memory management
}


MainWindow::~MainWindow()
{
    delete ui;
}

