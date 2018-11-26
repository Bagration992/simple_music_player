#ifndef GUICONTROLS_H
#define GUICONTROLS_H

#include "ui_mainwindow.h"
#include <phonon/VolumeSlider>

namespace Ui {
class GUIControls;
}

class GUIControls : public QObject {
    Q_OBJECT

public:
    GUIControls(); //?
    GUIControls(Ui::MainWindow *ui, QWidget *parent);
    //initVolumeSlider();

private:
    //volumeSlider
};

#endif // GUICONTROLS_H
