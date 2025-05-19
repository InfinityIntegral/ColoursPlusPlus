#ifndef SGEXPLAINPAGEMANAGEMENT_H
#define SGEXPLAINPAGEMANAGEMENT_H

#include <QObject>
#include "sgwidget000221103.h"
#include "sgtextbutton022211332.h"

class SGExplainPageManagement : public QObject
{
    Q_OBJECT
public:
    static void initialiseexplainpage();
    static SGWidget000221103* explainpagebackground;
    static SGTextButton022211332* restartbutton;
    static void restartapp();
private:
    SGExplainPageManagement(){}
    ~SGExplainPageManagement(){}
};

#endif // SGEXPLAINPAGEMANAGEMENT_H
