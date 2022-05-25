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
    foreach(const QString& olderkeys, m_jsonobject.keys())
    {
        QJsonValue value = m_jsonobject.value(olderkeys);
        QString strValue = value.toString();
        QByteArray utf8value;
        utf8value = QByteArray::fromBase64(strValue.toUtf8());
        strValue = QString(utf8value);
        m_labelmap->insert(olderkeys,strValue);
    }
    m_key = QString::number(key);
    qInfo() << "delete call for owner of a key:" << key;
    m_labelmap->remove(m_key);
    m_vmap.clear();
    QMapIterator<QString, QString> i(*m_labelmap);
    while (i.hasNext()) {
        i.next();
        m_vmap.insert(i.key(), i.value().toUtf8().toBase64()); //.toAscii().toHex(
    }
    m_jsonobject = QJsonObject::fromVariantMap(m_vmap);
    qInfo() << m_jsonobject;
    writeFile();
}


void serialize::edit(ChatLabel* input, int key)
{

    m_input = input;
    m_key = QString::number(key);
    qInfo() << input->getText();
    m_labelmap->insert(m_key,input->getText());
    QMapIterator<QString, QString> i(*m_labelmap);
    buildMap();
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
        QByteArray utf8value;
        utf8value = QByteArray::fromBase64(strValue.toUtf8());
        qInfo() << utf8value;
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
        temp_counter = 0;
        foreach(const QString& olderkeys, m_jsonobject.keys())
        {
            QJsonValue value = m_jsonobject.value(olderkeys);
            QString strValue = value.toString();
            QByteArray utf8value;
            utf8value = QByteArray::fromBase64(strValue.toUtf8());
            strValue = QString(utf8value);
            m_labelmap->insert(olderkeys,strValue);
            temp_counter ++;
        }

    }
    int sum = 0;
    sum = temp_counter;
    qInfo() << "Qstring key initially was:" << m_key;
    qInfo() << "sum of keys:" << sum;
    qInfo() << "Qstring updated to:" << m_key;

    m_labelmap->insert(m_key,(m_input->getText()));
    QMapIterator<QString, QString> i(*m_labelmap);
    while (i.hasNext()) {
        i.next();
        m_vmap.insert(i.key(), i.value().toUtf8().toBase64()); //.toAscii().toHex(
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
