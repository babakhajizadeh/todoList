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
    QMap<QString, QByteArray> *m_tasksMap; //pointer to map of tasks and their adresses
    QString m_fileName;       //binary file name
    QString key;              //QMap key used in json
    QDataStream m_streamOut;     //serializes data into binary
    QVariantMap m_vmap;         //helps write Qmap to json
    QFile* m_serializedFile;  //binaty file
    QByteArray* m_input;      //pointer holds bytearray from widget
    QJsonObject m_jsonobject; //json object of whole tasks
};

#endif // SERIALIZE_H
