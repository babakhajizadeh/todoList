#include "serialize.h"

serialize::serialize()
{
    qInfo() << "serializer constructed.";
}


serialize::~serialize()
{
    qInfo() << "serializer destructed.";
}

void serialize::serializer(ChatLabel* input, int key) //slot
{
    qInfo() <<"Serializer called!";

    m_input = input;
    m_key = QString::number(key);
    qInfo() << "method writeFile call";
    buildMap();
    writeFile();
}

void serialize::remove(int key)
{
    m_key = QString::number(key);
    qInfo() << "delete call for owner of a key:" << key;
    m_labelmap->remove(m_key);
    QMapIterator<QString, QString> i(*m_labelmap);
    m_vmap.clear();
    while (i.hasNext()) {
        i.next();
        m_vmap.insert(i.key(), i.value()); //i.value().toHex()
    }
    m_jsonobject = QJsonObject::fromVariantMap(m_vmap);
    qInfo() << m_jsonobject;
    writeFile();
}


void serialize::edit(ChatLabel* input, int key)
{
    m_input = input;
    m_key = QString::number(key);
    m_labelmap->insert(m_key,input->getText());
    QMapIterator<QString, QString> i(*m_labelmap);
    m_vmap.clear();
    while (i.hasNext()) {
        i.next();
        m_vmap.insert(i.key(), i.value()); //i.value().toHex()
    }
    m_jsonobject = QJsonObject::fromVariantMap(m_vmap);
    qInfo() << m_jsonobject;
    writeFile();
}


void serialize::deserializer() //slot
{
    qInfo() <<"DeSerializer called!";
}

void serialize::init()
{
    m_fileName = "tasks.txt";
    m_streamOut.setVersion(QDataStream::Qt_4_0);
    m_serializedFile = new QFile(m_fileName);
    m_serializedFile->open(QIODevice::WriteOnly);
    qInfo() << "Qfile tasks.txt created";
    m_serializedFile->close(); //empty tasks.txt generated
    m_labelmap = new QMap<QString, QString>;
}

void serialize::buildMap()
{
    m_labelmap->insert(m_key,(m_input->getText()));

    QMapIterator<QString, QString> i(*m_labelmap);

    while (i.hasNext()) {
        i.next();
        m_vmap.insert(i.key(), i.value()); //i.value().toHex()
    }
    m_jsonobject = QJsonObject::fromVariantMap(m_vmap);
    qInfo() << m_jsonobject;
}

void serialize::writeFile()
{
    //creats binary:
    m_serializedFile->open(QIODevice::WriteOnly);
    m_streamOut.setDevice(m_serializedFile);
    m_streamOut << m_jsonobject;
    m_serializedFile->close(); //flush every thing to file
    qInfo() << "binary file built.";

}
