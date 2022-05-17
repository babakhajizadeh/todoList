#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <QObject>
#include <QWidget>
#include <QJsonObject>
#include <QFile>
#include <QIODevice>
#include <QMap>

/*this class is reponsible in creating QJsonObject
 * out of user inputs and the serialize it to
 * a binary text file*/


class serialize : public QObject
{
    Q_OBJECT
public:
    serialize();
    ~serialize();

    void init();      //creats serilizer instance
    bool readFile();  //read back from binary
    void writeFile(QByteArray* input, int); //write json to binary

private:
    QMap<QString, QByteArray> *m_tasksMap; //map of tasks and their adresses
    QString m_fileName;
    QString key;
    QDataStream m_stream;
    QVariant vmap;
    QFile* m_serializedFile;
    QByteArray* m_input;
    QJsonObject m_jsonobject;
};

#endif // SERIALIZE_H
