#ifndef SGILLUSIONMANAGEMENT_H
#define SGILLUSIONMANAGEMENT_H

#include <QObject>
#include "sgwidget000221103.h"
#include "sgwidget000311104.h"
#include "sgcomplementarycolourrenderer.h"
#include "sgtextbutton022211332.h"

class SGIllusionManagement : public QObject
{
    Q_OBJECT
public:
    static void initialiseillusionpage();
    static SGWidget000221103* illusionpagebackground;
    static SGWidget000221103* illusionpagewhite;
    static int t;
    static QTimer* timer;
    static void refreshtimer();
    static SGWidget000311104* timeindicator;
    static SGComplementaryColourRenderer* renderer;
    static SGTextButton022211332* continuebutton;
    static void tonextpage();
private:
    SGIllusionManagement(){}
    ~SGIllusionManagement(){}
};

#endif // SGILLUSIONMANAGEMENT_H
