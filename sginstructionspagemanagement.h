#ifndef SGINSTRUCTIONSPAGEMANAGEMENT_H
#define SGINSTRUCTIONSPAGEMANAGEMENT_H

#include <QObject>
#include "sgwidget000221103.h"
#include "sgscrollview000231100.h"
#include "sgtextbutton022211332.h"
#include "sglayoutinstructionspage.h"
#include "sgtext011260021.h"

class SGInstructionsPageManagement : public QObject
{
    Q_OBJECT
public:
    static void initialiseinstructionspage();
    static void tonextpage();
    static SGWidget000221103* instructionspagebackground;
    static SGTextButton022211332* continuebutton;
    static SGScrollView000231100* instructionspagescrollview;
    static SGLayoutInstructionsPage* instructionspagelayout;
    static SGText011260021* instructionstext;
private:
    SGInstructionsPageManagement(){}
    ~SGInstructionsPageManagement(){}
};

#endif // SGINSTRUCTIONSPAGEMANAGEMENT_H
