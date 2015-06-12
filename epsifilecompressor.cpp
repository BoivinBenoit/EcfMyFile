#include "epsifilecompressor.h"

#include "filepool.h"
#include "writer.h"
#include "zipper.h"
#include "zippedbufferpool.h"
#include <memory>
#include <QDebug>

using namespace std;

EpsiFileCompressor::EpsiFileCompressor() :
    _threadCount(0)
{
    qDebug() << "Construtor EpsiFileCompressor";
}

EpsiFileCompressor::EpsiFileCompressor(int threadCount) :
    _threadCount(threadCount)
{
}

void EpsiFileCompressor::compress(const QString &folder, const QString &ecfFileName)
{
    qDebug() << "EpsiFileCompressor::compress(" << folder << "," << ecfFileName << ")";
    // Only works on folders
    FilePool filePool(folder);
    ZippedBufferPool zippedBufferPool;
    Writer* writer = new Writer(zippedBufferPool, ecfFileName);
    writer->start();

    QList<Zipper*> zippers;
    for (int i = 0; i < _threadCount; ++i) {
        zippers.append(new Zipper(filePool, zippedBufferPool, filePool._canonicalRootPath));
    }

    for (Zipper* zipper : zippers) {
        zipper->wait();
        delete zipper;
    }

    writer->wait();
    delete writer;
}

void EpsiFileCompressor::uncompress(const QString &ecfFileName, const QString &folder)
{
    qDebug() << "EpsiFileCompressor::uncompress(" << ecfFileName << "," << folder << ")";

    QFile compressedFile(ecfFileName);
    if(compressedFile.open(QFile::ReadOnly) == true){
        QByteArray uncompressedDatas = qUncompress(compressedFile.readAll());
        QFile uncompressedFile(folder+"uncompressed_"+ecfFileName);
        uncompressedFile.open(QFile::WriteOnly);
        QDataStream uncompressedStream(&uncompressedFile);
        //uncompressedStream.writeRawData(uncompressedArray.constData(),uncompressedArray.size());
    }

}
