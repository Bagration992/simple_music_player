#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QString>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = 0);

    void prepareForDownload(QString nameOfSong, QString nameOfArtist);
    void prepareForDownloadWiki(QString nameOFArtist);
    void doDownload();
    void doDownloadWiki();
    void readLyrics();
    void readWiki();
    QString getLyrics();
    QString getWiki();
    void setLyrics(QString str);
    void setWiki(QString str);

public slots:
    void replyFinished(QNetworkReply *reply);
    void replyFinishedWiki(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QString finalAdress;
    QString finalAdressWiki1;
    QString finalAdressWiki2;
    QString siteAdress;
    QString siteAdressWiki;
    QString artistName;
    QString songName;
    QString finalLyrics;
    QString finalWiki;
};

#endif // DOWNLOADER_H
