#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playingoptions.h"
#include "playlisttablemodel.h"
#include <QtGui>
#include <QAbstractItemView>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    widgetParent = new QWidget(parent);

    playingOptions = new PlayingOptions();
    playlistTableModel = new PlaylistTableModel(parent);

    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, parent);
    mediaObject = new Phonon::MediaObject(parent);

    mediaObject->setTickInterval(1000);

    Phonon::createPath(mediaObject, audioOutput);

    // inicijalizacija downloader-a
    downloader = new Downloader();
    nameOfCurrentArtist = "";
    nameOfCurrentSong = "";

    // inicijalizacija timera
    timerLyrics = new QTimer(this);
    QObject::connect(timerLyrics, SIGNAL(timeout()), this, SLOT(updateLyrics()));

    timerWiki = new QTimer(this);
    QObject::connect(timerWiki, SIGNAL(timeout()), this, SLOT(updateWiki()));

    // inicijalizuje se VolumeSlider
    ui->slVolumeSlider->setAudioOutput(audioOutput);
    ui->slVolumeSlider->setMuteVisible(true);

    // inicijalizuje se SeekSlider
    ui->slSeekSlider->setMediaObject(mediaObject);

    // podesavanja tabele
    ui->tableView->setModel(playlistTableModel);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->selectRow(0);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->resizeColumnToContents(0);
    ui->tableView->show();

    // inicijalizuje se labela za prikaz teksta
    lblText = new QLabel(parent);
    lblText->setStyleSheet("font: 10pt;");
    lblText->setMargin(4);
    lblText->setWordWrap(true);
    lblText->setStyleSheet("background-color: #99CCFF");

    ui->scrollArea->setWidget(lblText);

    //inicijalizacija tajmera
    ui->lcdNumber->display("00:00");

    ui->label_2->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    ui->label_2->setWordWrap(true);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setStyleSheet("background-color: #99CCFF");

    event = new QKeyEvent(QEvent::KeyPress, Qt::Key_Delete, Qt::NoModifier);

    // registruju se signali i odgovarajuci slotovi
    QObject::connect(ui->btnAddFiles, SIGNAL(clicked()), this, SLOT(onBtnAddFiles()));
    QObject::connect(ui->btnPlay, SIGNAL(clicked()), this, SLOT(onBtnPlay()));
    QObject::connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onDoubleClicked(QModelIndex)));
    QObject::connect(ui->btnPause, SIGNAL(clicked()), this, SLOT(onBtnPause()));
    QObject::connect(ui->btnStop, SIGNAL(clicked()), this, SLOT(onBtnStop()));
    QObject::connect(ui->btnNext, SIGNAL(clicked()), this, SLOT(onBtnNext()));
    QObject::connect(ui->btnPrevious, SIGNAL(clicked()), this, SLOT(onBtnPrevious()));
    QObject::connect(ui->btnSavePlaylist, SIGNAL(clicked()), this, SLOT(onBtnSavePlaylist()));
    QObject::connect(ui->btnOpenPlaylist, SIGNAL(clicked()), this, SLOT(onBtnOpenPlaylist()));
    QObject::connect(ui->btnNewPlaylist, SIGNAL(clicked()), this, SLOT(onBtnNewPlaylist()));
    QObject::connect(ui->btnSort, SIGNAL(clicked()), this, SLOT(onBtnSort()));
    QObject::connect(ui->btnShuffle, SIGNAL(clicked()), this, SLOT(onBtnShuffle()));
    QObject::connect(ui->btnAddFavourite, SIGNAL(clicked()), this, SLOT(onBtnAddFavourite()));
    QObject::connect(ui->btnAddToFavourite, SIGNAL(clicked()), this, SLOT(onBtnAddToFavourite()));
    QObject::connect(mediaObject, SIGNAL(aboutToFinish()), this, SLOT(enqueueNext()));
    QObject::connect(mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)), this, SLOT(stateChanged(Phonon::State, Phonon::State)));
    QObject::connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(tick(qint64)));
    QObject::connect(mediaObject, SIGNAL(currentSourceChanged(Phonon::MediaSource)), this, SLOT(changeLabel(Phonon::MediaSource)));
    QObject::connect(ui->pushButton_15, SIGNAL(clicked()), this, SLOT(onBtnSongInfo()));
    QObject::connect(ui->pushButton_14, SIGNAL(clicked()), this, SLOT(onBtnArtistInfo()));

    setWindowTitle("Player");
}

void MainWindow::onBtnAddFiles()
{
    playlistTableModel->addFiles(mediaObject);
    ui->tableView->selectRow(0);
}

void MainWindow::onBtnPlay()
{
    if (playlistTableModel->getTracks().isEmpty())
        return;

    playingOptions->play(ui, playlistTableModel, mediaObject);
}

void MainWindow::onDoubleClicked(QModelIndex)
{
    playingOptions->play(ui, playlistTableModel, mediaObject);
}

void MainWindow::onBtnPause()
{
    if (playlistTableModel->getTracks().isEmpty())
        return;

    playingOptions->pause(mediaObject);
}

void MainWindow::onBtnStop()
{
    if (playlistTableModel->getTracks().isEmpty())
        return;

    playingOptions->stop(mediaObject);
}

void MainWindow::onBtnNext()
{
    if (playlistTableModel->getTracks().isEmpty())
        return;

    playingOptions->next(ui, playlistTableModel, mediaObject);
}

void MainWindow::onBtnPrevious()
{
    if (playlistTableModel->getTracks().isEmpty())
        return;

    playingOptions->previous(ui, playlistTableModel, mediaObject);
}

void MainWindow::enqueueNext()
{
    playingOptions->enqueueNext(ui, playlistTableModel, mediaObject);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tick(qint64 time)
 {
    QTime displayTime(0, (time / 60000) % 60, (time / 1000) % 60);
    ui->lcdNumber->display(displayTime.toString("mm:ss"));
 }

void MainWindow::onBtnSavePlaylist()
{
    if (playlistTableModel->getTracks().isEmpty())
        return;

    //korisnik bira lokaciju
    QString fileName = QFileDialog::getSaveFileName(this, "Save Playlist",
                                                    QDesktopServices::storageLocation(QDesktopServices::MusicLocation),
                                                    "Playlist files (*.m3u)");

    //proverim da li je uneto ime fajla (cancel)
    if (fileName == "" || fileName==QDesktopServices::storageLocation(QDesktopServices::MusicLocation)+"/favourite")
        return ;
    else
        fileName.append(".m3u");

    //napravim fajl
    QFile playlist(fileName);

    //otvorim za pisanje
    if (playlist.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&playlist);
    //prva linija je tag
        stream << "#EXTM3U" << endl;
    //svaka sledeca se popunjava iz tabele:

        for (int index=0;index<playlistTableModel->rowCount();index++)
        {
            QString text = playlistTableModel->index(index, 2).data().toString() + " - " +
                          playlistTableModel->index(index, 1).data().toString();

            //tag (kolone: 2 - 1)
            stream << "#EXTINF:" << playlistTableModel->getMetaInformationAt(index)->totalTime()/1000 << "," << text << endl;
            //putanja
            stream << playlistTableModel->getTrackAt(index).fileName() << endl;
        }
    }

}

void MainWindow::onBtnOpenPlaylist()
{
    playlistTableModel->addList(mediaObject);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Delete) {
            playlistTableModel->deleteTrack(ui);
    }
    else if(event->key() == Qt::Key_Escape)
        this->close();
}

void MainWindow::onBtnSort()
{
    if (playlistTableModel->getTracks().isEmpty())
        return;

    playlistTableModel->sortPlaylist();
}

void MainWindow::onBtnShuffle()
{
    if (playlistTableModel->getTracks().isEmpty())
        return;

    playlistTableModel->shufflePlaylist(widgetParent);
}

//ovde cemo azurirati labelu sa imenom trenutno pustene pesme i tajmer
void MainWindow::stateChanged(Phonon::State newState, Phonon::State /*oldState*/)
{
    switch (newState) {
        case Phonon::PlayingState:
        {
            QMap<QString, QString> metaData = mediaObject->metaData();
            QString text = metaData.value("ARTIST")+" - "+metaData.value("TITLE");
            ui ->label_2->setText(text);

            QMap<QString, QString> metaData1 = mediaObject->metaData();
            nameOfCurrentArtist = metaData1.value("ARTIST");

            QMap<QString, QString> metaData2 = mediaObject->metaData();
            nameOfCurrentSong = metaData2.value("TITLE");

            break;
        }
        case Phonon::StoppedState:
        {
                ui->lcdNumber->display("00:00");
                break;
        }
        default:
                ;
    }
}

void MainWindow::onBtnNewPlaylist()
{
    if (playlistTableModel->getTracks().isEmpty())
        return;

    playlistTableModel->clear();
}

void MainWindow::changeLabel(Phonon::MediaSource)
{
    QMap<QString, QString> metaData = mediaObject->metaData();
    QString text = metaData.value("ARTIST")+" - "+metaData.value("TITLE");
    ui->label_2->setText(text);
}

void MainWindow::onBtnAddFavourite()
{
    playlistTableModel->addFavourite(mediaObject);
}

void MainWindow::onBtnAddToFavourite()
{
    //uzimam indeks selektovane pesme
    QModelIndex currentSelection = ui->tableView->selectionModel()->currentIndex();
    int index = currentSelection.row(); // indeks selektovane pesme

    //ako nije nista selektovano, ne radim nista
    if (!currentSelection.isValid())
        return ;

    //otvorim fajl
    QFile playlist(QDesktopServices::storageLocation(QDesktopServices::MusicLocation)+"/favourite.m3u");

    //ako fajl postoji, dodajem
    if (playlist.exists() && playlist.open(QIODevice::Append))
    {
        QTextStream stream(&playlist);

        QMap<QString, QString> metaData = playlistTableModel->getMetaInformationAt(index)->metaData();

        QString text = metaData.value("ARTIST") + " - " + metaData.value("TITLE");

        //tag (vreme, ime izvodjaca, naziv pesme)
        stream << "#EXTINF:" << playlistTableModel->getMetaInformationAt(index)->totalTime()/1000 << "," << text << endl;
        //putanja
        qDebug()<<"OK";
        stream << playlistTableModel->getTrackAt(index).fileName() << endl;
    }
    //ako ne postoji, pravim novu listu
    else if (playlist.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&playlist);

        stream << "#EXTM3U" << endl;

        QMap<QString, QString> metaData = playlistTableModel->getMetaInformationAt(index)->metaData();

        QString text = metaData.value("ARTIST") + " - " + metaData.value("TITLE");

        //tag (vreme, ime izvodjaca, naziv pesme)
        stream << "#EXTINF:" << playlistTableModel->getMetaInformationAt(index)->totalTime()/1000 << "," << text << endl;
        //putanja
        stream << playlistTableModel->getTrackAt(index).fileName() << endl;
    }

    playlist.close();
}

void MainWindow::onBtnSongInfo()
{
    downloader->prepareForDownload(nameOfCurrentSong, nameOfCurrentArtist);
    downloader->doDownload();
    timerLyrics->start(100);
}

void MainWindow::onBtnArtistInfo()
{
    downloader->prepareForDownloadWiki(nameOfCurrentArtist);
    downloader->doDownloadWiki();
    timerWiki->start(100);
}

void MainWindow::updateLyrics()
{
    if (!(downloader->getLyrics() == "")) {
        timerLyrics->stop();
        lblText->setText(downloader->getLyrics());
        downloader->setLyrics("");
    }
}

void MainWindow::updateWiki()
{
    if (!(downloader->getWiki() == "")){
        timerWiki->stop();
        lblText->setText(downloader->getWiki());
        downloader->setWiki("");
    }
}
