#include "playingoptions.h"
#include "ui_mainwindow.h"
#include "playlisttablemodel.h"
#include <phonon/MediaObject>
#include <QList>
#include <QStringList>
#include <QFileDialog>
#include <QDesktopServices>
#include <phonon/volumeslider.h>
#include <phonon/seekslider.h>
#include <QString>

PlayingOptions::PlayingOptions()
{

}

PlayingOptions::~PlayingOptions()
{

}

void PlayingOptions::play(Ui::MainWindow *ui, PlaylistTableModel *playlistTableModel, Phonon::MediaObject *mediaObject)
{
    QModelIndex currentSelection = ui->tableView->selectionModel()->currentIndex();
    int index = currentSelection.row(); // indeks selektovane pesme

    mediaObject->setCurrentSource(playlistTableModel->getTrackAt(index));
    mediaObject->play();
}

void PlayingOptions::pause(Phonon::MediaObject *mediaObject)
{
    if (mediaObject->state() == Phonon::PlayingState)
        mediaObject->pause();
}

void PlayingOptions::stop(Phonon::MediaObject *mediaObject)
{
    if (mediaObject->state() == Phonon::PlayingState ||
            mediaObject->state() == Phonon::PausedState) {
        mediaObject->stop();
    }
}

void PlayingOptions::next(Ui::MainWindow *ui, PlaylistTableModel *playlistTableModel, Phonon::MediaObject *mediaObject)
{    
    int size = playlistTableModel->getTracks().size();
    int i;

    for (i = 0; i < size; i++) {
        if (mediaObject->currentSource().fileName() == playlistTableModel->getTrackAt(i).fileName())
            break;
    }

    // ako ima bar jos jedna pesma posle trenutno pustene
    if (i < size - 1) {
        // ako je pesma aktivna, pusta se i sledeca
        if (mediaObject->state() == Phonon::PlayingState) {
            mediaObject->setCurrentSource(playlistTableModel->getTrackAt(i + 1));
            mediaObject->play();
        }
        // nijedna pesma nije aktivna,samo se priprema sledeca
        else {
            mediaObject->setCurrentSource(playlistTableModel->getTrackAt(i + 1));
        }
        // selektuje se sledeca
        ui->tableView->selectRow(i + 1);
    }
}

void PlayingOptions::previous(Ui::MainWindow *ui, PlaylistTableModel *playlistTableModel, Phonon::MediaObject *mediaObject)
{
    int size = playlistTableModel->getTracks().size();
    int i;

    for (i = 0; i < size; i++) {
        if (mediaObject->currentSource().fileName() == playlistTableModel->getTrackAt(i).fileName())
            break;
    }

    // ako postoji prethodna pesma u listi
    if (i != size && i > 0) {
        if (mediaObject->state() == Phonon::PlayingState) {
            mediaObject->setCurrentSource(playlistTableModel->getTrackAt(i - 1));
            mediaObject->play();
        }
        // nijedna pesma nije aktivna
        else {
            mediaObject->setCurrentSource(playlistTableModel->getTrackAt(i - 1));
        }
        // selektuje se prethodna
        ui->tableView->selectRow(i - 1);
    }
}


void PlayingOptions::enqueueNext(Ui::MainWindow *ui, PlaylistTableModel *playlistTableModel, Phonon::MediaObject *mediaObject)
{
    int size = playlistTableModel->getTracks().size();
    int i;

    for (i = 0; i < size; i++) {
        if (mediaObject->currentSource().fileName() == playlistTableModel->getTrackAt(i).fileName())
            break;
    }

    // ako postoji bar jos jedna pesma u listi
    if (i < size - 1) {
        mediaObject->enqueue(playlistTableModel->getTrackAt(i + 1));

        ui->tableView->selectRow(i + 1);
    }
}
