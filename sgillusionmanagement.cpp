#include "sgillusionmanagement.h"
#include "sgcentralmanagement.h"
#include "sggenerallibrary.h"
#include "sgselectpagemanagement.h"
#include "sgexplainpagemanagement.h"

SGWidget000221103* SGIllusionManagement::illusionpagebackground = nullptr;
int SGIllusionManagement::t = 1;
QTimer* SGIllusionManagement::timer = nullptr;
SGWidget000311104* SGIllusionManagement::timeindicator = nullptr;
SGComplementaryColourRenderer* SGIllusionManagement::renderer = nullptr;
SGTextButton022211332* SGIllusionManagement::continuebutton = nullptr;
#include <QDebug>
void SGIllusionManagement::initialiseillusionpage(){
    if(SGIllusionManagement::illusionpagebackground != nullptr){
        (*SGIllusionManagement::illusionpagebackground).show();
        (*SGIllusionManagement::timeindicator).show();
        qDebug() << "after reenabling: " << (*SGIllusionManagement::timeindicator).autoFillBackground();
        (*SGIllusionManagement::renderer).show();
        (*SGIllusionManagement::continuebutton).hide();
        QString white = "rgba(255, 255, 255, 255)";
        SGGeneralLibrary::SetUIStyle(SGIllusionManagement::illusionpagebackground, SGGeneralLibrary::stylesheetfieldbackgroundcolour, white);
        SGIllusionManagement::t = 20;
        (*SGIllusionManagement::timer).start(1000);
        (*SGIllusionManagement::timeindicator).w1 = 1.0f;
        qDebug() << "after setting w1: " << (*SGIllusionManagement::timeindicator).autoFillBackground();
        emit (*SGCentralManagement::signalsemitter).updateillusionpage();
        qDebug() << "after updating size on reenabling: " << (*SGIllusionManagement::timeindicator).autoFillBackground();
        return;
    }
    SGIllusionManagement::illusionpagebackground = new SGWidget000221103(SGCentralManagement::mainbackground, 0.0f, 0.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateillusionpage, SGIllusionManagement::illusionpagebackground, &SGWidget000221103::ResizeObj);
    QString white0 = "rgba(255, 255, 255, 255)";
    SGGeneralLibrary::SetUIStyle(SGIllusionManagement::illusionpagebackground, SGGeneralLibrary::stylesheetfieldbackgroundcolour, white0);
    SGIllusionManagement::timer = new QTimer(SGIllusionManagement::illusionpagebackground);
    connect(SGIllusionManagement::timer, &QTimer::timeout, &SGIllusionManagement::refreshtimer);
    (*SGIllusionManagement::timer).start(1000);
    SGIllusionManagement::timeindicator = new SGWidget000311104(SGIllusionManagement::illusionpagebackground, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateillusionpage, SGIllusionManagement::timeindicator, &SGWidget000311104::ResizeObj);
    qDebug() << "after creating: " << (*SGIllusionManagement::timeindicator).autoFillBackground();
    SGIllusionManagement::renderer = new SGComplementaryColourRenderer(SGIllusionManagement::illusionpagebackground);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateillusionpage, SGIllusionManagement::renderer, &SGComplementaryColourRenderer::ResizeObj);
    SGIllusionManagement::continuebutton = new SGTextButton022211332(SGIllusionManagement::illusionpagebackground, "view explanation", 0.0f, 1.0f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateillusionpage, SGIllusionManagement::continuebutton, &SGTextButton022211332::ResizeObj);
    connect(SGIllusionManagement::continuebutton, &SGTextButton022211332::clicked, &SGIllusionManagement::tonextpage);
    (*SGIllusionManagement::continuebutton).hide();
}

void SGIllusionManagement::refreshtimer(){
    SGIllusionManagement::t--;
    (*SGIllusionManagement::timeindicator).w1 = (float)SGIllusionManagement::t / 20.0f;
    (*SGIllusionManagement::timeindicator).ResizeObj();
    qDebug() << "after updating count: " << (*SGIllusionManagement::timeindicator).autoFillBackground();
    if(SGIllusionManagement::t == 0){
        qDebug() << "after time is up: " << (*SGIllusionManagement::timeindicator).autoFillBackground();
        (*SGIllusionManagement::timer).stop();
        if(SGSelectPageManagement::selectedtype == 1){
            QString black = "rgba(0, 0, 0, 255)";
            SGGeneralLibrary::SetUIStyle(SGIllusionManagement::illusionpagebackground, SGGeneralLibrary::stylesheetfieldbackgroundcolour, black);
        }
        else if(SGSelectPageManagement::selectedtype == 2){
            QString white = "rgba(255, 255, 255, 255)";
            SGGeneralLibrary::SetUIStyle(SGIllusionManagement::illusionpagebackground, SGGeneralLibrary::stylesheetfieldbackgroundcolour, white);
        }
        else if(SGSelectPageManagement::selectedtype == 3){
            QString col = SGGeneralLibrary::ColourUintToCSS(SGGeneralLibrary::maxsaturatedcolour(SGSelectPageManagement::selectedhue));
            SGGeneralLibrary::SetUIStyle(SGIllusionManagement::illusionpagebackground, SGGeneralLibrary::stylesheetfieldbackgroundcolour, col);
        }
        qDebug() << "before disabling: " << (*SGIllusionManagement::timeindicator).autoFillBackground();
        (*SGIllusionManagement::timeindicator).hide();
        (*SGIllusionManagement::renderer).hide();
        (*SGIllusionManagement::continuebutton).show();
    }
}

void SGIllusionManagement::tonextpage(){
    (*SGIllusionManagement::illusionpagebackground).hide();
    SGExplainPageManagement::initialiseexplainpage();
}
