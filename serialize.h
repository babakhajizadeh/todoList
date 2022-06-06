#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <QObject>
#include <QWidget>
#include <QJsonObject>
#include <QFile>
#include <QIODevice>
#include <QMap>
#include "chatlabel.h"
#include <QFileInfo>
#include <unistd.h>

/**
 * @brief The class of serializaton and deserialization of IO.   
 * 
 * This class is one of the largest class with several slots and signals 
 * takes responsiblity of reading and writing stream of data to 
 * and from a binary file located at build directory. It recieves datas in 
 * form inctance objects of class ChatLabel and thier unique keys.
 * it came up with slots such as \ref serializer() which reads ChatLabel objects, 
 * remove() and edit() slots manage to modify and delete todo tasks labels 
 * as well ass deserializer() slot wich resotre data from last session,
 * right before program's closure. 
 * */


class serialize : public QObject //has no widget
{
    Q_OBJECT
public:
    serialize();
    ~serialize();
    void init();      //creats serilizer instance
    void writeFile(); //writes json to binary
    void buildMap();

signals:
    void jsonReady(QByteArray *value, int key);

public slots:
    void serializer(ChatLabel* input, int key);
    void remove(int key);   
    void edit(ChatLabel* underEdit, int underEditkey);
    void deserializer();


private:
    QMap<QString, QString>* m_labelmap; //pointer to map of tasks and their adresses
    QString m_fileName;       ///binary file name
    QString m_key;              ///QMap key used in json
    int intkey;                  ///class chatlabel works with type int
    QDataStream m_streamOut;     ///serializes data into binary
    QDataStream m_streamIn;
    QVariantMap m_vmap;         ///helps write Qmap to json
    QFile* m_serializedFile;  ///binaty file
    ChatLabel* m_input;      ///pointer holds bytearray from widget
    QJsonObject m_jsonobject; ///json object of whole tasks
};

#endif // SERIALIZE_H
