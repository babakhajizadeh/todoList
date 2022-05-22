#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <QObject>
#include <QWidget>
#include <QJsonObject>
#include <QFile>
#include <QIODevice>
#include <QMap>
#include "chatlabel.h"

/*this class is reponsible in creating QJsonObject
 * out of user inputs and the serialize it to
 * a binary text file*/


class serialize : public QObject //has no widget
{
    Q_OBJECT
public:
    serialize();
    ~serialize();
    void init();      //creats serilizer instance
    bool readFile();  //read back from binary
    void writeFile(); //write json to binary
    void buildMap();

public slots:
    void serializer(ChatLabel* input, int key);
    void remove(int key);    // when need to deletes
    void edit(ChatLabel* underEdit, int underEditkey);
    void deserializer();



private:
    QMap<QString, QString>* m_labelmap; //pointer to map of tasks and their adresses
    QString m_fileName;       //binary file name
    QString m_key;              //QMap key used in json
    QDataStream m_streamOut;     //serializes data into binary
    QVariantMap m_vmap;         //helps write Qmap to json
    QFile* m_serializedFile;  //binaty file
    ChatLabel* m_input;      //pointer holds bytearray from widget
    QJsonObject m_jsonobject; //json object of whole tasks
};

#endif // SERIALIZE_H
