#include "sgexplainpagemanagement.h"
#include "sgcentralmanagement.h"
#include "sggenerallibrary.h"
#include "sgintropagemanagement.h"
#include <QDesktopServices>
#include <QUrl>

SGWidget000221103* SGExplainPageManagement::explainpagebackground = nullptr;
SGTextButton022211332* SGExplainPageManagement::restartbutton = nullptr;
SGScrollView000231100* SGExplainPageManagement::explainpagescrollview = nullptr;
SGLayoutExplainPage* SGExplainPageManagement::explainpagelayout = nullptr;
SGText011260021* SGExplainPageManagement::explaintext = nullptr;
SGTextButton022110032* SGExplainPageManagement::moreinfobutton = nullptr;

QString SGExplainPageManagement::infotext = "    Did you see a circle with a colour that appears impossibly saturated? This is caused by the following process.\n    Your eyes detect light using 3 types of cone cells each having a type of pigment. When looking at a high saturation colour like the circle that you looked at, some types of cone cells are stimulated much more than others and quickly deplete the pigment. When the circle is removed, the cone cells with their pigment depleted respond less to light, thus creating a tint opposite to the colour of the circle. This tint is called an afterimage. The afterimage being overlaid on top of black, white, and a fully saturated colour will give stygian, self-luminous, and hyperbolic colours respectively.\n    Calculations for the RGB coordinates below can be found in the \"more information\" link. For you to see the impossible colour without the afterimage effect, the screen need to display the colour: RGB";

void SGExplainPageManagement::initialiseexplainpage(){
    if(SGExplainPageManagement::explainpagebackground != nullptr){
        (*SGExplainPageManagement::explainpagebackground).show();
        emit (*SGCentralManagement::signalsemitter).updateexplainpage();
        return;
    }
    SGExplainPageManagement::explainpagebackground = new SGWidget000221103(SGCentralManagement::mainbackground, 0.0f, 0.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateexplainpage, SGExplainPageManagement::explainpagebackground, &SGWidget000221103::ResizeObj);
    SGExplainPageManagement::restartbutton = new SGTextButton022211332(SGExplainPageManagement::explainpagebackground, "restart", 0.0f, 1.0f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateexplainpage, SGExplainPageManagement::restartbutton, &SGTextButton022211332::ResizeObj);
    connect(SGExplainPageManagement::restartbutton, &SGTextButton022211332::clicked, &SGExplainPageManagement::restartapp);
    SGExplainPageManagement::explainpagescrollview = new SGScrollView000231100(SGExplainPageManagement::explainpagebackground, 0.0f, 0.0f, 1.0f, -1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateexplainpage, SGExplainPageManagement::explainpagescrollview, &SGScrollView000231100::ResizeObj);
    SGExplainPageManagement::explainpagelayout = new SGLayoutExplainPage(SGExplainPageManagement::explainpagescrollview);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateexplainpage, SGExplainPageManagement::explainpagelayout, &SGLayoutExplainPage::ReceiveUpdateCall);
    (*SGExplainPageManagement::explainpagescrollview).setWidget(SGExplainPageManagement::explainpagelayout);
    (*SGExplainPageManagement::explainpagelayout).ReceiveUpdateCall();
    SGExplainPageManagement::explaintext = new SGText011260021(SGExplainPageManagement::explainpagelayout, SGExplainPageManagement::infotext, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateexplainpage, SGExplainPageManagement::explaintext, &SGText011260021::ResizeObj);
    SGExplainPageManagement::moreinfobutton = new SGTextButton022110032(SGExplainPageManagement::explainpagelayout, "more information", 5.5f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateexplainpage, SGExplainPageManagement::moreinfobutton, &SGTextButton022110032::ResizeObj);
    connect(SGExplainPageManagement::moreinfobutton, &SGTextButton022110032::clicked, &SGExplainPageManagement::seemoreinfo);
}

void SGExplainPageManagement::restartapp(){
    (*SGExplainPageManagement::explainpagebackground).hide();
    SGIntroPageManagement::initialiseintropage();
}

void SGExplainPageManagement::seemoreinfo(){
    QDesktopServices::openUrl(QUrl("https://yandex.com"));
}
