#include "sgintropagemanagement.h"
#include "sgcentralmanagement.h"

SGWidget000221103* SGIntroPageManagement::intropagebackground = nullptr;
SGScrollView000231100* SGIntroPageManagement::intropagescrollview = nullptr;
SGLayoutIntroPage* SGIntroPageManagement::intropagelayout = nullptr;
SGText022110021* SGIntroPageManagement::apptitle = nullptr;
SGText011260021* SGIntroPageManagement::infotext = nullptr;
SGTextButton022211332* SGIntroPageManagement::continuebutton = nullptr;

void SGIntroPageManagement::initialiseintropage(){
    if(SGIntroPageManagement::intropagebackground != nullptr){
        (*SGIntroPageManagement::intropagebackground).show();
        emit (*SGCentralManagement::signalsemitter).updateintropage();
        return;
    }
    SGIntroPageManagement::intropagebackground = new SGWidget000221103(SGCentralManagement::mainbackground, 0.0f, 0.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateintropage, SGIntroPageManagement::intropagebackground, &SGWidget000221103::ResizeObj);
    SGIntroPageManagement::continuebutton = new SGTextButton022211332(SGIntroPageManagement::intropagebackground, "continue", 0.0f, 1.0f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateintropage, SGIntroPageManagement::continuebutton, &SGTextButton022211332::ResizeObj);
    connect(SGIntroPageManagement::continuebutton, &SGTextButton022211332::clicked, &SGIntroPageManagement::tonextpage);
    SGIntroPageManagement::intropagescrollview = new SGScrollView000231100(SGIntroPageManagement::intropagebackground, 0.0f, 0.0f, 1.0f, -1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateintropage, SGIntroPageManagement::intropagescrollview, &SGScrollView000231100::ResizeObj);
    SGIntroPageManagement::intropagelayout = new SGLayoutIntroPage(SGIntroPageManagement::intropagescrollview);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateintropage, SGIntroPageManagement::intropagelayout, &SGLayoutIntroPage::ReceiveUpdateCall);
    SGIntroPageManagement::apptitle = new SGText022110021(SGIntroPageManagement::intropagelayout, "Colours++", 6.0f, 2.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateintropage, SGIntroPageManagement::apptitle, &SGText022110021::ResizeObj);
    QString infostring = "    Colours++ is an application for you to visualise impossible colours, colours that are not possible to see under normal conditions. You may choose between 3 types of impossible colours, that is stygian, self-luminous, and hyperbolic colours. Stygian colours appear as dark as black but are saturated, self-luminous colours appear brighter than white despite being saturated, and hyperbolic colours appear more saturated than what should be possible. At the end of the visualisation, explanation of why impossible colours, in addition to an estimate of the perceived colour in RGB coordinates, will be provided.";
    SGIntroPageManagement::infotext = new SGText011260021(SGIntroPageManagement::intropagelayout, infostring, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateintropage, SGIntroPageManagement::infotext, &SGText011260021::ResizeObj);
}

void SGIntroPageManagement::tonextpage(){
    (*SGIntroPageManagement::intropagebackground).hide();
}
