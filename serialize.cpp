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


void serialize::deserializer() //mthod for deserializing
{
    qInfo()<< "file exit deserializer activated.";
    m_serializedFile->open(QIODevice::ReadOnly);
    m_streamIn.setVersion(QDataStream::Qt_4_0);
    m_streamIn.setDevice(m_serializedFile);
    m_streamIn >> m_jsonobject;
    m_serializedFile->close(); //flush every thing to file
    qInfo() << "json read:" << m_jsonobject;
    foreach(const QString& key, m_jsonobject.keys()) {
        QJsonValue value = m_jsonobject.value(key);
        QString strValue = value.toString();
        intkey = key.toInt();
        QByteArray utf8value = strValue.toUtf8().constData();
        emit jsonReady(&utf8value, intkey);
    }
}

void serialize::init()
{
    qInfo() << "serializer object constructed";
    m_fileName = "tasks.txt";
    m_serializedFile = new QFile(m_fileName);
    m_labelmap = new QMap<QString, QString>;
    m_streamOut.setVersion(QDataStream::Qt_4_0);
    if(QFileInfo::exists(m_fileName)) //cheks wheter any record exist.
    {
        qInfo() << "deserilizer is about to be called.";
        deserializer();
    }
    else
    {
        m_streamOut.setVersion(QDataStream::Qt_4_0);
        m_serializedFile = new QFile(m_fileName);
        m_serializedFile->open(QIODevice::WriteOnly);
        qInfo() << "Qfile tasks.txt created";
        m_serializedFile->close(); //empty tasks.txt generated
    }
}

void serialize::buildMap()
{
    int temp_counter = 0;
    if(QFileInfo::exists(m_fileName)) //cheks wheter any record exist.
    {

        foreach(const QString& olderkeys, m_jsonobject.keys())
        {
            QJsonValue value = m_jsonobject.value(olderkeys);
            QString strValue = value.toString();
            m_labelmap->insert(olderkeys,strValue);
            temp_counter ++;
        }
    }
    int sum = 0;
    sum += temp_counter;
    sum += m_key.toInt();
    qInfo() << "Qstring key initially was:" << m_key;
    m_key = QString::number(sum);
    qInfo() << "sum of keys:" << sum;
    qInfo() << "Qstring updated to:" << m_key;

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
//    delete m_labelmap;
}
