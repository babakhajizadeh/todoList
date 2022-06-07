#ifndef ADDBUTTON_H
#define ADDBUTTON_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QHBoxLayout>

/**
 * @brief This class provides simple pushbutton as main ADD button.
 * 
 * The system's Return key also set to work similar with this button.
 */


class addButton: public QWidget
{
    Q_OBJECT
public:
    addButton();
    ~addButton();
    void init();

private:
    QPushButton* add; //for either add or edit buttons
    QHBoxLayout* parentLayout;

signals:
    void addButtonClicked();


};

#endif // ADDBUTTON_H
