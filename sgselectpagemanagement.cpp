#include "sgselectpagemanagement.h"
#include "sgcentralmanagement.h"
#include "sggenerallibrary.h"
#include "sgintropagemanagement.h"
#include "sginstructionspagemanagement.h"

SGWidget000221103* SGSelectPageManagement::selectpagebackground = nullptr;
SGTextButton022314332* SGSelectPageManagement::backbutton = nullptr;
SGTextButton022314332* SGSelectPageManagement::continuebutton = nullptr;
SGScrollView000231100* SGSelectPageManagement::selectpagescrollview = nullptr;
SGLayoutSelectPage* SGSelectPageManagement::selectpagelayout = nullptr;
SGText012110021* SGSelectPageManagement::typeprompt = nullptr;
SGTextButton022110032* SGSelectPageManagement::stygianbutton = nullptr;
SGTextButton022110032* SGSelectPageManagement::selfluminousbutton = nullptr;
SGTextButton022110032* SGSelectPageManagement::hyperbolicbutton = nullptr;
SGText012110021* SGSelectPageManagement::hueprompt = nullptr;
SGHueSelectRenderer* SGSelectPageManagement::hueselector = nullptr;
float SGSelectPageManagement::selectedhue = 0.0f;
int SGSelectPageManagement::selectedtype = 3;

void SGSelectPageManagement::initialiseselectpage(){
    if(SGSelectPageManagement::selectpagebackground != nullptr){
        (*SGSelectPageManagement::selectpagebackground).show();
        SGSelectPageManagement::sethyperbolic();
        SGSelectPageManagement::selectedhue = 0.0f;
        (*SGSelectPageManagement::hueselector).update();
        emit (*SGCentralManagement::signalsemitter).updateselectpage();
        return;
    }
    SGSelectPageManagement::selectpagebackground = new SGWidget000221103(SGCentralManagement::mainbackground, 0.0f, 0.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::selectpagebackground, &SGWidget000221103::ResizeObj);
    SGSelectPageManagement::backbutton = new SGTextButton022314332(SGSelectPageManagement::selectpagebackground, "back", 0.0f, 0.0f, 1.0f, 0.5f, 0.0f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::backbutton, &SGTextButton022314332::ResizeObj);
    connect(SGSelectPageManagement::backbutton, &SGTextButton022314332::clicked, &SGSelectPageManagement::tolastpage);
    SGSelectPageManagement::continuebutton = new SGTextButton022314332(SGSelectPageManagement::selectpagebackground, "continue", 0.5f, 0.0f, 1.0f, 0.5f, 0.0f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::continuebutton, &SGTextButton022314332::ResizeObj);
    connect(SGSelectPageManagement::continuebutton, &SGTextButton022314332::clicked, &SGSelectPageManagement::tonextpage);
    SGSelectPageManagement::selectpagescrollview = new SGScrollView000231100(SGSelectPageManagement::selectpagebackground, 0.0f, 0.0f, 1.0f, -1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::selectpagescrollview, &SGScrollView000231100::ResizeObj);
    SGSelectPageManagement::selectpagelayout = new SGLayoutSelectPage(SGSelectPageManagement::selectpagescrollview);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::selectpagelayout, &SGLayoutSelectPage::ReceiveUpdateCall);
    (*SGSelectPageManagement::selectpagescrollview).setWidget(SGSelectPageManagement::selectpagelayout);
    SGSelectPageManagement::typeprompt = new SGText012110021(SGSelectPageManagement::selectpagelayout, "choose type of impossible colour...", 10.5f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::typeprompt, &SGText012110021::ResizeObj);
    SGSelectPageManagement::stygianbutton = new SGTextButton022110032(SGSelectPageManagement::selectpagelayout, "stygian", 2.5f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::stygianbutton, &SGTextButton022110032::ResizeObj);
    connect(SGSelectPageManagement::stygianbutton, &SGTextButton022110032::clicked, &SGSelectPageManagement::setstygian);
    SGSelectPageManagement::selfluminousbutton = new SGTextButton022110032(SGSelectPageManagement::selectpagelayout, "self-luminous", 4.5f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::selfluminousbutton, &SGTextButton022110032::ResizeObj);
    connect(SGSelectPageManagement::selfluminousbutton, &SGTextButton022110032::clicked, &SGSelectPageManagement::setselfluminous);
    SGSelectPageManagement::hyperbolicbutton = new SGTextButton022110032(SGSelectPageManagement::selectpagelayout, "hyperbolic", 3.5f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::hyperbolicbutton, &SGTextButton022110032::ResizeObj);
    connect(SGSelectPageManagement::hyperbolicbutton, &SGTextButton022110032::clicked, &SGSelectPageManagement::sethyperbolic);
    SGSelectPageManagement::hueprompt = new SGText012110021(SGSelectPageManagement::selectpagelayout, "choose hue of impossible colour...", 10.0f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::hueprompt, &SGText012110021::ResizeObj);
    SGSelectPageManagement::hueselector = new SGHueSelectRenderer(SGSelectPageManagement::selectpagelayout);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateselectpage, SGSelectPageManagement::hueselector, &SGHueSelectRenderer::ResizeObj);
}

void SGSelectPageManagement::tolastpage(){
    (*SGSelectPageManagement::selectpagebackground).hide();
    SGIntroPageManagement::initialiseintropage();
}

void SGSelectPageManagement::tonextpage(){
    (*SGSelectPageManagement::selectpagebackground).hide();
    SGInstructionsPageManagement::initialiseinstructionspage();
}

void SGSelectPageManagement::setstygian(){
    SGSelectPageManagement::selectedtype = 1;
    SGGeneralLibrary::SetUIStyle(SGSelectPageManagement::stygianbutton, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour1);
    SGGeneralLibrary::SetUIStyle(SGSelectPageManagement::selfluminousbutton, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour3);
    SGGeneralLibrary::SetUIStyle(SGSelectPageManagement::hyperbolicbutton, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour3);
}

void SGSelectPageManagement::setselfluminous(){
    SGSelectPageManagement::selectedtype = 2;
    SGGeneralLibrary::SetUIStyle(SGSelectPageManagement::stygianbutton, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour3);
    SGGeneralLibrary::SetUIStyle(SGSelectPageManagement::selfluminousbutton, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour1);
    SGGeneralLibrary::SetUIStyle(SGSelectPageManagement::hyperbolicbutton, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour3);
}

void SGSelectPageManagement::sethyperbolic(){
    SGSelectPageManagement::selectedtype = 3;
    SGGeneralLibrary::SetUIStyle(SGSelectPageManagement::stygianbutton, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour3);
    SGGeneralLibrary::SetUIStyle(SGSelectPageManagement::selfluminousbutton, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour3);
    SGGeneralLibrary::SetUIStyle(SGSelectPageManagement::hyperbolicbutton, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour1);
}
