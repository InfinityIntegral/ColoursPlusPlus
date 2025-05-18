#ifndef SGSELECTPAGEMANAGEMENT_H
#define SGSELECTPAGEMANAGEMENT_H

#include <QObject>
#include "sgwidget000221103.h"
#include "sgtextbutton022314332.h"
#include "sgscrollview000231100.h"
#include "sglayoutselectpage.h"
#include "sgtext012110021.h"
#include "sgtextbutton022110032.h"
#include "sghueselectrenderer.h"

class SGSelectPageManagement : public QObject
{
    Q_OBJECT
public:
    static void initialiseselectpage();
    static SGWidget000221103* selectpagebackground;
    static SGTextButton022314332* backbutton;
    static SGTextButton022314332* continuebutton;
    static void tolastpage();
    static void tonextpage();
    static SGScrollView000231100* selectpagescrollview;
    static SGLayoutSelectPage* selectpagelayout;
    static SGText012110021* typeprompt;
    static SGTextButton022110032* stygianbutton;
    static SGTextButton022110032* selfluminousbutton;
    static SGTextButton022110032* hyperbolicbutton;
    static void setstygian();
    static void setselfluminous();
    static void sethyperbolic();
    static SGText012110021* hueprompt;
    static SGHueSelectRenderer* hueselector;
    static float selectedhue;
    static int selectedtype;
private:
    SGSelectPageManagement(){}
    ~SGSelectPageManagement(){}
};

#endif // SGSELECTPAGEMANAGEMENT_H
