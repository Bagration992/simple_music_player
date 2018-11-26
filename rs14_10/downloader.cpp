#include "downloader.h"
#include <QRegExp>

Downloader::Downloader(QObject *parent) :
    QObject(parent)
{
    finalAdress = "";
    finalAdressWiki1 = "";
    finalAdressWiki2 = "";
    siteAdress = "http://www.azlyrics.com/lyrics/";
    siteAdressWiki = "http://en.wikipedia.org/wiki/";
}

QString Downloader::getLyrics(){
    return finalLyrics;
}

void Downloader::setLyrics(QString str)
{
    finalLyrics = str;
}

void Downloader::doDownload(){
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl(finalAdress)));
    finalAdress = "";
}

void Downloader::replyFinished(QNetworkReply *reply){
    if(reply->error()){
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else{
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

        QFile *file = new QFile("downloaded.txt");
        if(file->open(QIODevice::WriteOnly)){
            file->write(reply->readAll());
            file->flush();
            file->close();
        }

        this->readLyrics();
    }

    reply->deleteLater();
}

void Downloader::prepareForDownload(QString nameOfSong, QString nameOfArtist){
    finalAdress.append(siteAdress);

    if (nameOfArtist.startsWith("The"))
        nameOfArtist.remove(0, 3);

    QRegExp re("[\.,’\'\?!#)\(-]");

    nameOfArtist.remove(re);

    finalAdress.append(nameOfArtist);
    finalAdress.append("/");

    nameOfSong.remove(re);

    finalAdress.append(nameOfSong);
    finalAdress.append(".html");

    QRegExp rx(" +");

    finalAdress.replace(rx, "");
    finalAdress = finalAdress.toLower();

    qDebug() << nameOfArtist;
    qDebug() << nameOfSong;
    qDebug() << finalAdress;
}

void Downloader::readLyrics(){
    QFile file("downloaded.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "error opening file: " << file.error();
        return;
    }

    QTextStream instream(&file);
    QString textInString;
    textInString=instream.readAll();

    QRegExp re("(<!-- start of lyrics -->((.+|\n)+)<!-- end of lyrics -->)");

    if(re.indexIn(textInString) > -1){
        finalLyrics = re.cap(2);
        finalLyrics.remove("<br />");
        finalLyrics.remove("<i>");
        finalLyrics.remove("</i>");
        //qDebug() << finalLyrics;
    }
    else {
        qDebug() << "no match";
    }

    return;
}

QString Downloader::getWiki(){
    return finalWiki;
}

void Downloader::setWiki(QString str){
    finalWiki = str;
}

void Downloader::prepareForDownloadWiki(QString nameOFArtist){
    finalAdressWiki1.append(siteAdressWiki);
    finalAdressWiki1.append(nameOFArtist);

    finalAdressWiki2.append(siteAdressWiki);
    finalAdressWiki2.append(nameOFArtist);

    QRegExp re(" +");
    finalAdressWiki1.replace(re, "_");
    finalAdressWiki2.replace(re, "_");

    finalAdressWiki1.append("_(band)");

    qDebug() << finalAdressWiki1;
    qDebug() << finalAdressWiki2;
}

void Downloader::doDownloadWiki(){
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinishedWiki(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl(finalAdressWiki1)));
    manager->get(QNetworkRequest(QUrl(finalAdressWiki2)));

    finalAdressWiki1 = "";
    finalAdressWiki2 = "";
}

void Downloader::replyFinishedWiki(QNetworkReply *reply){
    if(reply->error()){
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else {
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

        QFile *file = new QFile("downloadedWiki.txt");
        if(file->open(QIODevice::WriteOnly)){
            file->write(reply->readAll());
            file->flush();
            file->close();
        }

        finalAdressWiki1 = "";
        finalAdressWiki2 = "";

        this->readWiki();
    }

    reply->deleteLater();
}

void Downloader::readWiki(){
    QFile file("downloadedWiki.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "error opening file: " << file.error();
        return;
    }

    QTextStream instream(&file);
    QString textInString;
    textInString=instream.readAll();

    QRegExp re("(<p>((.+|\n)+)</p>)");
    //re.setMinimal(true);

    if(re.indexIn(textInString) > -1){
        finalWiki = re.cap(1);

        QRegExp ra("<a href=(.|\n)+>");
        ra.setMinimal(true);
        finalWiki.remove(ra);

        QRegExp rb("<.+>");
        rb.setMinimal(true);
        finalWiki.remove(rb);

        QRegExp rc("<//.+>");
        rc.setMinimal(true);
        finalWiki.remove(rc);

        QRegExp rd("\n+");
        finalWiki.replace(rd, "\n\n");

        finalWiki.remove("[edit]");
    }
    else {
        qDebug() << "no match";
    }

    return;
}
