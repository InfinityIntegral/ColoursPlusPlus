#ifndef SGINTROPAGEMANAGEMENT_H
#define SGINTROPAGEMANAGEMENT_H

#include <QObject>
#include "sgwidget000221103.h"
#include "sgscrollview000231100.h"
#include "sglayoutintropage.h"
#include "sgtext022110021.h"
#include "sgtext011260021.h"
#include "sgtextbutton022211332.h"

class SGIntroPageManagement : public QObject
{
    Q_OBJECT
public:
    static void initialiseintropage();
    static SGWidget000221103* intropagebackground;
    static SGScrollView000231100* intropagescrollview;
    static SGLayoutIntroPage* intropagelayout;
    static SGText022110021* apptitle;
    static SGText011260021* infotext;
    static SGTextButton022211332* continuebutton;
    static void tonextpage();
private:
    SGIntroPageManagement(){}
    ~SGIntroPageManagement(){}
};

#endif // SGINTROPAGEMANAGEMENT_H
