#include "serialize.h"

serialize::serialize()
{
    qInfo() << "serializer constructed.";
}

serialize::~serialize()
{
    qInfo() << "serializer destructed.";
}

void serialize::init()
{
    m_fileName = "tasks.txt";
    m_stream.setVersion(QDataStream::Qt_5_15);
    m_serializedFile = new QFile(m_fileName);
    m_serializedFile->open(QIODevice::WriteOnly);
    qInfo() << "Qfile tasks.txt created";
    m_serializedFile->close(); //empty tasks.txt generated
    m_tasksMap = new QMap<QString, QByteArray>;
}

void serialize::writeFile(QByteArray* input, int intkey)
{
    qInfo() << *input;
    key = QString::number(intkey);
    m_tasksMap->insert(key,*input);
    QVariantMap vmap;
    QMapIterator<QString, QByteArray> i(*m_tasksMap);
    while (i.hasNext()) {
        i.next();
        vmap.insert(i.key(), i.value());
    }
    m_jsonobject = QJsonObject::fromVariantMap(vmap);
    qInfo() << "json count:" << m_jsonobject.count();
    qInfo() << m_jsonobject;
}
