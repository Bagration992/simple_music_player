#ifndef PLAYINGOPTIONS_H
#define PLAYINGOPTIONS_H

#include "ui_mainwindow.h"
#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>
#include "playlisttablemodel.h"

namespace Ui {
class PlayingOptions;
}

class PlayingOptions : public QObject {
    Q_OBJECT

public:
    PlayingOptions();
    ~PlayingOptions();
    void play(Ui::MainWindow *ui, PlaylistTableModel *playlistTableModel, Phonon::MediaObject *mediaObject);
    void pause(Phonon::MediaObject *mediaObject);
    void stop(Phonon::MediaObject *mediaObject);
    void previous(Ui::MainWindow *ui, PlaylistTableModel *playlistTableModel, Phonon::MediaObject *mediaObject);
    void next(Ui::MainWindow *ui, PlaylistTableModel *playlistTableModel, Phonon::MediaObject *mediaObject);
    void enqueueNext(Ui::MainWindow *ui, PlaylistTableModel *playlistTableModel, Phonon::MediaObject *mediaObject);
};

#endif // PLAYINGOPTIONS_H
