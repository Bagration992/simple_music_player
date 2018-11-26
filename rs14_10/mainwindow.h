#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon/audiooutput.h>
#include <phonon/mediaobject.h>
#include "playingoptions.h"
#include "guicontrols.h"
#include "playlisttablemodel.h"
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtGui>
#include "downloader.h"
#include <QTimer>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //Phonon::MediaObject* getMetaInformation() const;

private:
    Ui::MainWindow *ui;
    QWidget *widgetParent;
    PlayingOptions *playingOptions;
    GUIControls *guiControls;
    PlaylistTableModel *playlistTableModel;
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    QKeyEvent *event;
    Downloader *downloader;
    QString nameOfCurrentArtist;
    QString nameOfCurrentSong;
    QTimer *timerLyrics;
    QTimer *timerWiki;
    QLabel *lblText;

public:
    void keyPressEvent(QKeyEvent *event);

public slots:
    void stateChanged(Phonon::State, Phonon::State);
    void onBtnAddFiles();
    void onBtnPlay();
    void onDoubleClicked(QModelIndex);
    void onBtnPause();
    void onBtnStop();
    void onBtnNext();
    void onBtnPrevious();
    void enqueueNext();
    void tick(qint64 time);
    void onBtnSavePlaylist();
    void onBtnOpenPlaylist();
    void onBtnNewPlaylist();
    void onBtnSort();
    void onBtnShuffle();
    void onBtnAddFavourite();
    void onBtnAddToFavourite();
    void changeLabel(Phonon::MediaSource);
    void onBtnSongInfo();
    void onBtnArtistInfo();
    void updateLyrics();
    void updateWiki();
};

#endif // MAINWINDOW_H
