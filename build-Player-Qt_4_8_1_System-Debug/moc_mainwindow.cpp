/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../rs14_10/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      72,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
     113,   11,   11,   11, 0x0a,
     126,   11,   11,   11, 0x0a,
     138,   11,   11,   11, 0x0a,
     150,   11,   11,   11, 0x0a,
     166,   11,   11,   11, 0x0a,
     185,  180,   11,   11, 0x0a,
     198,   11,   11,   11, 0x0a,
     218,   11,   11,   11, 0x0a,
     238,   11,   11,   11, 0x0a,
     257,   11,   11,   11, 0x0a,
     269,   11,   11,   11, 0x0a,
     284,   11,   11,   11, 0x0a,
     304,   11,   11,   11, 0x0a,
     326,   11,   11,   11, 0x0a,
     359,   11,   11,   11, 0x0a,
     375,   11,   11,   11, 0x0a,
     393,   11,   11,   11, 0x0a,
     408,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0,\0stateChanged(Phonon::State,Phonon::State)\0"
    "onBtnAddFiles()\0onBtnPlay()\0"
    "onDoubleClicked(QModelIndex)\0onBtnPause()\0"
    "onBtnStop()\0onBtnNext()\0onBtnPrevious()\0"
    "enqueueNext()\0time\0tick(qint64)\0"
    "onBtnSavePlaylist()\0onBtnOpenPlaylist()\0"
    "onBtnNewPlaylist()\0onBtnSort()\0"
    "onBtnShuffle()\0onBtnAddFavourite()\0"
    "onBtnAddToFavourite()\0"
    "changeLabel(Phonon::MediaSource)\0"
    "onBtnSongInfo()\0onBtnArtistInfo()\0"
    "updateLyrics()\0updateWiki()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 1: _t->onBtnAddFiles(); break;
        case 2: _t->onBtnPlay(); break;
        case 3: _t->onDoubleClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: _t->onBtnPause(); break;
        case 5: _t->onBtnStop(); break;
        case 6: _t->onBtnNext(); break;
        case 7: _t->onBtnPrevious(); break;
        case 8: _t->enqueueNext(); break;
        case 9: _t->tick((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 10: _t->onBtnSavePlaylist(); break;
        case 11: _t->onBtnOpenPlaylist(); break;
        case 12: _t->onBtnNewPlaylist(); break;
        case 13: _t->onBtnSort(); break;
        case 14: _t->onBtnShuffle(); break;
        case 15: _t->onBtnAddFavourite(); break;
        case 16: _t->onBtnAddToFavourite(); break;
        case 17: _t->changeLabel((*reinterpret_cast< Phonon::MediaSource(*)>(_a[1]))); break;
        case 18: _t->onBtnSongInfo(); break;
        case 19: _t->onBtnArtistInfo(); break;
        case 20: _t->updateLyrics(); break;
        case 21: _t->updateWiki(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
