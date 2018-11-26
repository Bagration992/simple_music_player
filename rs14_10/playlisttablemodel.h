#ifndef PLAYLISTTABLEMODEL_H
#define PLAYLISTTABLEMODEL_H

#include <QAbstractTableModel>
#include <phonon/MediaSource>
#include <phonon/MediaObject>
#include "ui_mainwindow.h"

namespace Ui {
class PlaylistTableModel;
}

bool mySort(const Phonon::MediaObject *lhs, const Phonon::MediaObject *rhs);

class PlaylistTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    PlaylistTableModel(QObject *parent);
    ~PlaylistTableModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void addFiles(Phonon::MediaObject *metaInitializer);
    bool insertRows(int position, int rows, const QModelIndex &index);
    bool removeRows(int row, int count, const QModelIndex &parent);
    const QList<Phonon::MediaSource> & getTracks() const;
    Phonon::MediaSource getTrackAt(int i);
    Phonon::MediaObject* getMetaInformationAt(int i);
    void addList(Phonon::MediaObject* metaInitializer);
    void deleteTrack(Ui::MainWindow *ui);
    void sortPlaylist();
    void shufflePlaylist(QWidget *widgetParent);
    void clear();
    void addFavourite(Phonon::MediaObject* metaInitializer);

private:
    QList<Phonon::MediaSource> tracks;
    QList<Phonon::MediaObject*> metaInformation;
};

#endif // PLAYLISTTABLEMODEL_H
