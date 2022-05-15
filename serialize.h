#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <QObject>
#include <QWidget>
#include <QJsonDocument>
#include <QFile>
#include <QIODevice>

/*this class is reponsible in creating QJsonObject
 * out of user inputs and the serialize it to
 * a binary text file*/


class serialize
{
    Q_OBJECT
public:
    serialize();

    void init(QByteArray* input);
    bool readFile;
    bool writeFile;

private:
    QString m_fileName = "tasks.txt";
    QDataStream* m_stream;
    QFile* m_serializedFile;
    QByteArray* m_input;
    QJsonObject* m_object;
    int m_keyCounter;
};

#endif // SERIALIZE_H
