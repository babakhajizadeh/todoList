#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chatbox.h"
#include "addbutton.h"


class Mainchatbox;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
private:
    Ui::MainWindow *ui;
    Mainchatbox* m_chatbox;
    addButton* m_add;

};
#endif // MAINWINDOW_H
