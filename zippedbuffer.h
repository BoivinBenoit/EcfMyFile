#ifndef ZIPPEDBUFFER_H
#define ZIPPEDBUFFER_H

#include <QString>
#include <QByteArray>
#include <QDataStream>

class ZippedBuffer
{
public:
    ZippedBuffer();
    void write(QDataStream &stream);
    void read(QDataStream &stream);
    void setRelativePath(QString path);
    void setZippedData(QByteArray zippedData);
private:
    QString _relativePath;
    QByteArray _zippedData;
};

#endif // ZIPPEDBUFFER_H
