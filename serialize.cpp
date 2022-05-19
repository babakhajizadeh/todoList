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
    m_streamOut.setVersion(QDataStream::Qt_4_0);
    m_serializedFile = new QFile(m_fileName);
    m_serializedFile->open(QIODevice::WriteOnly);
    qInfo() << "Qfile tasks.txt created";
    m_serializedFile->close(); //empty tasks.txt generated
    m_tasksMap = new QMap<QString, QByteArray>;
    // m_tasksMap needs to be deleted manually
}

void serialize::writeFile(QByteArray* input, int intkey)
{
    qInfo() << *input;
    key = QString::number(intkey);
    m_tasksMap->insert(key,*input);

    // Qmap iteration for deleting tasks goes here
    //Edit button

    // creating json out of QMap
    m_vmap.clear();
    QMapIterator<QString, QByteArray> i(*m_tasksMap);
    while (i.hasNext()) {
        i.next();
        m_vmap.insert(i.key(), i.value().toHex());
    }
    m_jsonobject = QJsonObject::fromVariantMap(m_vmap);
    qInfo() << m_jsonobject;

    //creats binary:
    m_serializedFile->open(QIODevice::WriteOnly);
    m_streamOut.setDevice(m_serializedFile);
    m_streamOut << m_jsonobject;
    m_serializedFile->close(); //flush every thing to file


    qInfo() << "binary file built.";

}
