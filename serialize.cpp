#include "serialize.h"

/**
 * @brief Constructs a new serialize::serialize object.
 * 
 * also notifies it's success by message to stderr of console 
 */
serialize::serialize()
{
    qInfo() << "serializer constructed.";
}

/**
 * @brief Destroys the serialize::serialize object.
 * 
 * also notifies it's success by message to stderr 
 */
serialize::~serialize()
{
    qInfo() << "serializer destructed.";
}


/**
 * @brief This a core member slot recieves each todo list task label objects as pointers of type ChatLabel and as well as it's respective unique keys.
 * 
 * Once Serializer triggered by signal @ref Widget::chatLabelObjectConstructed(), It initializes a private pointer 
 * to those instance objects and calls proper functions afterwards which is buildMap() and writeFile().
 * 
 * @param input 
 * a pointer to an object of type ChatLabel
 * @param key
 * A corresponding identifier of each ChatLabel objects. as used in  maps and Json object. provided by class Mainchatbox
 * 
 */
void serialize::serializer(ChatLabel* input, int key) //slot
{
    qInfo() <<"Serializer called!";

    m_input = input;
    m_key = QString::number(key);
    qInfo() << "method writeFile call";
    buildMap();
    writeFile();
}

/**
 * @brief This member slot take responsiblity of deleting class ChatLable instance objects.
 * 
 * once Delete button being pressed by End User it emits signal of Widget::labelObjectDeleteRequest
 * from mainwondow which triggers this slot. it takes responsiblity of deleting objects of class
 * ChatLabel by recieving it's corresponding key. So it first removes from Json object then calls
 * methods writeFile() to update changes to binary file on the disk.
 * 
 * @param key 
 * A corresponding identifier of each ChatLabel objects. as used in  maps and Json object. provided by class Mainchatbox
 */

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

/**
 * @brief This member slot takes reponsibility of modifying class ChatLabel instance objects.
 * 
 * once edit button being pressed by End User it emits signal of Mainchatbox::editready 
 * which triggers this slot. It takes a pointer to an istance of class ChatLabel and it's corresponding key
 * then it inserts in to a map of objects by calling method of buildMap() to update changes, and calls
 * writeFile() afterwards to save changes to binary file on the disk.
 * 
 * @param input 
 * A pointer to instance of class ChatLabel
 * @param key 
 * A corresponding identifier of each ChatLabel objects. as used in  maps and Json object. provided by class Mainchatbox
 */


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

/**
 * @brief This is one of the key methods of class \ref serialize takes job of deserialization.
 * 
 * It manages to read from binary file and regenerate last state of tasks as they were 
 * formerly objects of class ChatLabel from last runtime session. When instance of class \ref serialize 
 * initilized in main widget the init() checks whether a binary file exist from last run and if so,
 * it calls this method, once called it deserialize binary in to a Json file and emits signal serialize::jsonReady
 * once emited it triggers slot Widget::controller which is responsible in creating back each ChatLabel objects.
 * 
 */
void serialize::deserializer() //mthod for deserializing
{
    qInfo()<< "file exit deserializer activated.";
    m_serializedFile->open(QIODevice::ReadOnly);
    m_streamIn.setVersion(QDataStream::Qt_4_0);
    m_streamIn.setDevice(m_serializedFile);
    QDataStream & operator<< (QDataStream& m_streamIn, const QJsonObject& m_jsonobject);
    QDataStream & operator>> (QDataStream& m_streamIn, QJsonObject& m_jsonobject);
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

/**
 * @brief Method for early initilize of the \ref serialize class instance 
 * once the program being executed. 
 * 
 * The init() normally initilize class instance for serilization task right after being constructed.
 * init method also checks if whether the serialized binary file from last time exist or if 
 * it needs a fresh initialization, repectively it either decides to call deserializer method or 
 * initialize a new binary file. 
 */
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


/**
 * @brief This is a member method which helps to establish a Map data structure.
 *  
 * This calss creats a map data structure of ChatLabel type from recorded Json object can be called via method 
 * \ref serializer() and edit().
 */
void serialize::buildMap()
{
    int temp_counter = 0;
    if(QFileInfo::exists(m_fileName)) //checks wheter any record exist.
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

/**
 * @brief Method to write binary json to file.
 * 
 * This method can called by the other methos of class \ref serialize to save changes to binary file.
 * 
 */
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
