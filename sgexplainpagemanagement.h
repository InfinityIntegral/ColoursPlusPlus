#ifndef SGEXPLAINPAGEMANAGEMENT_H
#define SGEXPLAINPAGEMANAGEMENT_H

#include <QObject>
#include "sgwidget000221103.h"
#include "sgtextbutton022211332.h"
#include "sgscrollview000231100.h"
#include "sglayoutexplainpage.h"
#include "sgtext011260021.h"
#include "sgtextbutton022110032.h"

class SGExplainPageManagement : public QObject
{
    Q_OBJECT
public:
    static void initialiseexplainpage();
    static SGWidget000221103* explainpagebackground;
    static SGTextButton022211332* restartbutton;
    static void restartapp();
    static SGScrollView000231100* explainpagescrollview;
    static SGLayoutExplainPage* explainpagelayout;
    static SGText011260021* explaintext;
    static QString infotext;
    static SGTextButton022110032* moreinfobutton;
    static void seemoreinfo();
private:
    SGExplainPageManagement(){}
    ~SGExplainPageManagement(){}
};

#endif // SGEXPLAINPAGEMANAGEMENT_H
