#include "playlisttablemodel.h"
#include "playingoptions.h"
#include <QList>
#include <QStringList>
#include <mediaobject.h>
#include <phonon/MediaObject>
#include <QFileDialog>
#include <QDesktopServices>
#include <phonon/MediaSource>
#include <iostream>
#include <fstream>
#include <QtAlgorithms>
#include <algorithm>

PlaylistTableModel::PlaylistTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

PlaylistTableModel::~PlaylistTableModel()
{
    for (int i = 0; i < metaInformation.size(); i++)
        delete metaInformation.at(i);
}

int PlaylistTableModel::rowCount(const QModelIndex & /*parent*/) const
{
   return tracks.size();
}

int PlaylistTableModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 6;
}

QVariant PlaylistTableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    if (row>=tracks.size() || row<0)
        return QVariant();

    if (role == Qt::DisplayRole && tracks.size()>0)
    {
        QMap<QString, QString> metaData = metaInformation.at(row)->metaData();

        QString title = metaData.value("TITLE");
        if (title == "")
            title = metaInformation.at(row)->currentSource().fileName();

        if (col == 0)
            return QString::number(row+1);
        if (col == 1)
            return title;
        if (col == 2)
            return metaData.value("ARTIST");
        if (col == 3)
            return metaData.value("ALBUM");
        if (col == 4)
            return metaData.value("DATE");
        if (col == 5)
            return metaData.value("GENRE");

    }
    if (role == Qt::FontRole && col==0)
    {
        QFont boldFont;
        boldFont.setBold(true);
        return boldFont;
    }

    return QVariant();
}

QVariant PlaylistTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role==Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("No");
            case 1:
                return QString("Title");
            case 2:
                return QString("Artist");
            case 3:
                return QString("Album");
            case 4:
                return QString("Year");
            case 5:
                return QString("Genre");
            }
        }
    }
    return QVariant();
}

void PlaylistTableModel::addFiles(Phonon::MediaObject *metaInitializer)
{
    QStringList files = QFileDialog::getOpenFileNames(0, "Choose files",
                                                      QDesktopServices::storageLocation(QDesktopServices::MusicLocation),
                                                      "Music files (*.mp3 *.ogg *.oga *.wma *.flac *.wav *.m4a)");
    if (files.isEmpty())
        return;

    int oldSize = tracks.size();

    foreach (QString file, files) {
        Phonon::MediaSource source(file);
        Phonon::MediaObject* tmp = new Phonon::MediaObject(metaInitializer->parent());
        metaInformation.append(tmp);

        int i = metaInformation.size()-1;

        metaInformation.at(i)->setCurrentSource(source);
        tracks.append(source);

    }

    this->insertRows(oldSize, tracks.size() - oldSize, QModelIndex());
}

bool PlaylistTableModel::insertRows(int position, int rows, const QModelIndex &index)
 {
     Q_UNUSED(index);
     beginInsertRows(QModelIndex(), position, position + rows - 1);

     endInsertRows();
     return true;
 }

const QList<Phonon::MediaSource> & PlaylistTableModel::getTracks() const
{
    return this->tracks;
}

QWidget* metaSend(QWidget *parent)
{
    return parent;
}

Phonon::MediaSource PlaylistTableModel::getTrackAt(int i)
{
    return tracks.at(i);
}

Phonon::MediaObject* PlaylistTableModel::getMetaInformationAt(int i)
{
    return metaInformation.at(i);
}

void PlaylistTableModel::addList(Phonon::MediaObject* metaInitializer)
{
    //otvorim prozor i korisnik bira playlistu
    QString fileName = QFileDialog::getOpenFileName(0, "Open Playlist",
                                                    QDesktopServices::storageLocation(QDesktopServices::MusicLocation),
                                                    "Playlist files (*.m3u)");
    //provera
    if (fileName == "")
        return ;

    //otvorim izabrani fajl za citanje
    QFile playlist(fileName);
    if (playlist.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&playlist);

        int oldSize = tracks.size();
        //citam svaki red i proveravam:
        while (!stream.atEnd())
        {
            //ako pocinje tarabom, preskacem ga
            QString line = stream.readLine();

            if ( line.at(0) == '#')
                continue ;

            //inace ga DODAJEM u tabelu i u tracks (playlisttablemodel)
            Phonon::MediaSource source(line);
            Phonon::MediaObject* tmp = new Phonon::MediaObject(metaInitializer->parent());
            metaInformation.append(tmp);

            int i = metaInformation.size()-1;

            metaInformation.at(i)->setCurrentSource(source);
            tracks.append(source);

        }

        this->insertRows(oldSize, tracks.size() - oldSize, QModelIndex());
        playlist.close();
    }
}

void PlaylistTableModel::deleteTrack(Ui::MainWindow *ui)
{
    if (!metaInformation.isEmpty()) {

        QModelIndex currentSelection = ui->tableView->selectionModel()->currentIndex();
        int index = currentSelection.row();

        for (int i = index; i + 1 < metaInformation.size(); i++) {
            metaInformation.at(i)->setCurrentSource(metaInformation.at(i+1)->currentSource());

        }

        metaInformation.removeAt(metaInformation.size() - 1);

        this->removeRows(index, 1, QModelIndex());
    }
}

bool PlaylistTableModel::removeRows (int row, int count, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), row, row + count - 1);

    for (int i = 0; i < count; ++i)
    {
        tracks.removeAt(row);
    }

    endRemoveRows();

    return true;
}

void PlaylistTableModel::shufflePlaylist(QWidget *widgetParent)
{
    std::random_shuffle(tracks.begin(), tracks.end());
    metaInformation.clear();

    int i = 0;

    foreach(Phonon::MediaSource src, tracks) {
        Phonon::MediaSource source(src);
        Phonon::MediaObject *tmp = new Phonon::MediaObject(widgetParent);

        metaInformation.append(tmp);
        metaInformation.at(i)->setCurrentSource(source);

        i++;
    }

    QModelIndex topLeft = createIndex(0, 0);
    QModelIndex bottomRight = createIndex(tracks.size()-1, 5);

    emit dataChanged(topLeft, bottomRight);
}

bool mySort(const Phonon::MediaObject *lhs, const Phonon::MediaObject *rhs)
{
    QMap<QString, QString> metaData1 = lhs->metaData();
    QMap<QString, QString> metaData2 = rhs->metaData();

    return (metaData1.value("ARTIST") < metaData2.value("ARTIST"));
}

void PlaylistTableModel::sortPlaylist()
{
    qSort(metaInformation.begin(), metaInformation.end(), mySort);

    tracks.clear();

    for (int i=0;i<metaInformation.size();i++)
    {
        tracks.append(metaInformation.at(i)->currentSource());
    }

    QModelIndex topLeft = createIndex(0, 0);
    QModelIndex bottomRight = createIndex(tracks.size()-1, 5);

    emit dataChanged(topLeft, bottomRight);

}

void PlaylistTableModel::clear()
{
    int n = tracks.size();
    metaInformation.clear();
    tracks.clear();
    for (int i=0;i<n;i++)
        this->removeRows(0, 1, QModelIndex());

    QModelIndex topLeft = createIndex(0, 0);
    QModelIndex bottomRight = createIndex(n - 1, 5);

    emit dataChanged(topLeft, bottomRight);
}

void PlaylistTableModel::addFavourite(Phonon::MediaObject* metaInitializer)
{
    //otvorim izabrani fajl za citanje
    QFile playlist(QDesktopServices::storageLocation(QDesktopServices::MusicLocation)+"/favourite.m3u");

    //ako lista ne postoji, nista dok se ne napravi prilikom dodavanja prvog fajla
    //ako postoji, citamo fajlove iz nje
    if (playlist.exists() && playlist.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&playlist);

        int oldSize = tracks.size();
        //citam svaki red i proveravam:
        while (!stream.atEnd())
        {
            //ako pocinje tarabom, preskacem ga
            QString line = stream.readLine();

            if ( line.at(0) == '#')
                continue ;

            //inace ga DODAJEM u tabelu i u tracks (playlisttablemodel)
            Phonon::MediaSource source(line);
            Phonon::MediaObject* tmp = new Phonon::MediaObject(metaInitializer->parent());
            metaInformation.append(tmp);

            int i = metaInformation.size()-1;

            metaInformation.at(i)->setCurrentSource(source);
            tracks.append(source);

        }

        this->insertRows(oldSize, tracks.size() - oldSize, QModelIndex());
        playlist.close();
    }
}
