/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <phonon/seekslider.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    Phonon::VolumeSlider *slVolumeSlider;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnPlay;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QPushButton *btnPrevious;
    QPushButton *btnNext;
    QPushButton *btnAddToFavourite;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_21;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *btnAddFiles;
    QPushButton *btnAddFavourite;
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    Phonon::SeekSlider *slSeekSlider;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnNewPlaylist;
    QPushButton *btnSavePlaylist;
    QPushButton *btnOpenPlaylist;
    QPushButton *btnSort;
    QPushButton *btnShuffle;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(958, 606);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        slVolumeSlider = new Phonon::VolumeSlider(centralWidget);
        slVolumeSlider->setObjectName(QString::fromUtf8("slVolumeSlider"));
        slVolumeSlider->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(slVolumeSlider, 2, 10, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        btnPlay = new QPushButton(centralWidget);
        btnPlay->setObjectName(QString::fromUtf8("btnPlay"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnPlay->sizePolicy().hasHeightForWidth());
        btnPlay->setSizePolicy(sizePolicy);
        btnPlay->setMinimumSize(QSize(35, 37));
        btnPlay->setMaximumSize(QSize(37, 37));
        btnPlay->setStyleSheet(QString::fromUtf8("background-image: url(:/1396546849_player_play.png);"));

        horizontalLayout->addWidget(btnPlay);

        btnPause = new QPushButton(centralWidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        sizePolicy.setHeightForWidth(btnPause->sizePolicy().hasHeightForWidth());
        btnPause->setSizePolicy(sizePolicy);
        btnPause->setMinimumSize(QSize(35, 37));
        btnPause->setMaximumSize(QSize(37, 37));
        btnPause->setStyleSheet(QString::fromUtf8("background-image: url(:/1396546912_player_pause.png);"));

        horizontalLayout->addWidget(btnPause);

        btnStop = new QPushButton(centralWidget);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        sizePolicy.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy);
        btnStop->setMinimumSize(QSize(35, 37));
        btnStop->setMaximumSize(QSize(37, 37));
        btnStop->setStyleSheet(QString::fromUtf8("background-image: url(:/1396546877_player_stop.png);"));
        btnStop->setIconSize(QSize(14, 14));

        horizontalLayout->addWidget(btnStop);

        btnPrevious = new QPushButton(centralWidget);
        btnPrevious->setObjectName(QString::fromUtf8("btnPrevious"));
        sizePolicy.setHeightForWidth(btnPrevious->sizePolicy().hasHeightForWidth());
        btnPrevious->setSizePolicy(sizePolicy);
        btnPrevious->setMinimumSize(QSize(35, 37));
        btnPrevious->setMaximumSize(QSize(37, 37));
        btnPrevious->setStyleSheet(QString::fromUtf8("background-image: url(:/1396548295_player_rev.png);"));

        horizontalLayout->addWidget(btnPrevious);

        btnNext = new QPushButton(centralWidget);
        btnNext->setObjectName(QString::fromUtf8("btnNext"));
        sizePolicy.setHeightForWidth(btnNext->sizePolicy().hasHeightForWidth());
        btnNext->setSizePolicy(sizePolicy);
        btnNext->setMinimumSize(QSize(35, 37));
        btnNext->setMaximumSize(QSize(37, 37));
        btnNext->setStyleSheet(QString::fromUtf8("background-image: url(:/1396548288_player_fwd.png);"));

        horizontalLayout->addWidget(btnNext);

        btnAddToFavourite = new QPushButton(centralWidget);
        btnAddToFavourite->setObjectName(QString::fromUtf8("btnAddToFavourite"));
        sizePolicy.setHeightForWidth(btnAddToFavourite->sizePolicy().hasHeightForWidth());
        btnAddToFavourite->setSizePolicy(sizePolicy);
        btnAddToFavourite->setMinimumSize(QSize(35, 37));
        btnAddToFavourite->setMaximumSize(QSize(37, 37));
        btnAddToFavourite->setStyleSheet(QString::fromUtf8("background-image: url(:/1396548538_package_favorite.png);"));

        horizontalLayout->addWidget(btnAddToFavourite);


        gridLayout_2->addLayout(horizontalLayout, 2, 9, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 1, 1, 1, 9);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        gridLayout_2->addLayout(verticalLayout_2, 4, 1, 1, 5);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 286, 341));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_21->addWidget(scrollArea);


        gridLayout_2->addLayout(verticalLayout_21, 4, 1, 1, 5);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 7, 1, 2);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMaximumSize(QSize(60, 50));
        lcdNumber->setFrameShape(QFrame::StyledPanel);
        lcdNumber->setFrameShadow(QFrame::Sunken);
        lcdNumber->setLineWidth(2);
        lcdNumber->setMidLineWidth(0);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(5);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(0));
        lcdNumber->setProperty("intValue", QVariant(0));

        gridLayout_2->addWidget(lcdNumber, 3, 4, 1, 1);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 4, 6, 1, 5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnAddFiles = new QPushButton(centralWidget);
        btnAddFiles->setObjectName(QString::fromUtf8("btnAddFiles"));
        btnAddFiles->setMaximumSize(QSize(16777215, 50));
        btnAddFiles->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);"));

        verticalLayout->addWidget(btnAddFiles);

        btnAddFavourite = new QPushButton(centralWidget);
        btnAddFavourite->setObjectName(QString::fromUtf8("btnAddFavourite"));
        btnAddFavourite->setMaximumSize(QSize(16777215, 50));
        btnAddFavourite->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);"));

        verticalLayout->addWidget(btnAddFavourite);

        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setMaximumSize(QSize(16777215, 50));
        pushButton_15->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);"));

        verticalLayout->addWidget(pushButton_15);

        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setMaximumSize(QSize(16777215, 50));
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);"));

        verticalLayout->addWidget(pushButton_14);


        gridLayout_2->addLayout(verticalLayout, 4, 0, 1, 1);

        slSeekSlider = new Phonon::SeekSlider(centralWidget);
        slSeekSlider->setObjectName(QString::fromUtf8("slSeekSlider"));
        slSeekSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(slSeekSlider, 3, 8, 1, 2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(false);

        gridLayout_2->addWidget(label_2, 2, 2, 1, 6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        btnNewPlaylist = new QPushButton(centralWidget);
        btnNewPlaylist->setObjectName(QString::fromUtf8("btnNewPlaylist"));
        sizePolicy.setHeightForWidth(btnNewPlaylist->sizePolicy().hasHeightForWidth());
        btnNewPlaylist->setSizePolicy(sizePolicy);
        btnNewPlaylist->setMinimumSize(QSize(30, 25));
        btnNewPlaylist->setMaximumSize(QSize(30, 25));
        btnNewPlaylist->setStyleSheet(QString::fromUtf8("background-image: url(:/1396553305_playlist-new.png);"));

        horizontalLayout_2->addWidget(btnNewPlaylist);

        btnSavePlaylist = new QPushButton(centralWidget);
        btnSavePlaylist->setObjectName(QString::fromUtf8("btnSavePlaylist"));
        sizePolicy.setHeightForWidth(btnSavePlaylist->sizePolicy().hasHeightForWidth());
        btnSavePlaylist->setSizePolicy(sizePolicy);
        btnSavePlaylist->setMinimumSize(QSize(30, 25));
        btnSavePlaylist->setMaximumSize(QSize(30, 25));
        btnSavePlaylist->setStyleSheet(QString::fromUtf8("background-image: url(:/1396553490_document-save-as.png);"));

        horizontalLayout_2->addWidget(btnSavePlaylist);

        btnOpenPlaylist = new QPushButton(centralWidget);
        btnOpenPlaylist->setObjectName(QString::fromUtf8("btnOpenPlaylist"));
        sizePolicy.setHeightForWidth(btnOpenPlaylist->sizePolicy().hasHeightForWidth());
        btnOpenPlaylist->setSizePolicy(sizePolicy);
        btnOpenPlaylist->setMinimumSize(QSize(30, 25));
        btnOpenPlaylist->setMaximumSize(QSize(30, 25));
        btnOpenPlaylist->setStyleSheet(QString::fromUtf8("background-image: url(:/1396553387_kde-folder-open.png);"));

        horizontalLayout_2->addWidget(btnOpenPlaylist);

        btnSort = new QPushButton(centralWidget);
        btnSort->setObjectName(QString::fromUtf8("btnSort"));
        btnSort->setMinimumSize(QSize(30, 25));
        btnSort->setMaximumSize(QSize(30, 25));
        btnSort->setStyleSheet(QString::fromUtf8("background-image: url(:/sort_az.png);"));

        horizontalLayout_2->addWidget(btnSort);

        btnShuffle = new QPushButton(centralWidget);
        btnShuffle->setObjectName(QString::fromUtf8("btnShuffle"));
        btnShuffle->setMinimumSize(QSize(30, 25));
        btnShuffle->setMaximumSize(QSize(30, 25));
        btnShuffle->setStyleSheet(QString::fromUtf8("background-image: url(:/media_playlist_shuffle.png);"));

        horizontalLayout_2->addWidget(btnShuffle);


        gridLayout_2->addLayout(horizontalLayout_2, 6, 7, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 958, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        slVolumeSlider->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Volume</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        btnPlay->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Play</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnPlay->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnPause->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Play</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnPause->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnStop->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Stop</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnStop->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnPrevious->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Previous track</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnPrevious->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnNext->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Next track</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnNext->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnAddToFavourite->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Love track</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnAddToFavourite->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Player", 0, QApplication::UnicodeUTF8));
        btnAddFiles->setText(QApplication::translate("MainWindow", "Files", 0, QApplication::UnicodeUTF8));
        btnAddFavourite->setText(QApplication::translate("MainWindow", "Favourite", 0, QApplication::UnicodeUTF8));
        pushButton_15->setText(QApplication::translate("MainWindow", "Lyrics", 0, QApplication::UnicodeUTF8));
        pushButton_14->setText(QApplication::translate("MainWindow", "Artist info", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "currently playing", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnNewPlaylist->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>New playlist</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnNewPlaylist->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnSavePlaylist->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Save playlist</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnSavePlaylist->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnOpenPlaylist->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Open playlist</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnOpenPlaylist->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnSort->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Sort playlist</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnSort->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnShuffle->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Shuffle playlist</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnShuffle->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
