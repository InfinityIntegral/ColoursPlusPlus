#include "sginstructionspagemanagement.h"
#include "sgcentralmanagement.h"
#include "sggenerallibrary.h"

SGWidget000221103* SGInstructionsPageManagement::instructionspagebackground = nullptr;
SGTextButton022211332* SGInstructionsPageManagement::continuebutton = nullptr;
SGScrollView000231100* SGInstructionsPageManagement::instructionspagescrollview = nullptr;
SGLayoutInstructionsPage* SGInstructionsPageManagement::instructionspagelayout = nullptr;
SGText011260021* SGInstructionsPageManagement::instructionstext = nullptr;

void SGInstructionsPageManagement::initialiseinstructionspage(){
    if(SGInstructionsPageManagement::instructionspagebackground != nullptr){
        (*SGInstructionsPageManagement::instructionspagebackground).show();
        emit (*SGCentralManagement::signalsemitter).updateinstructionspage();
        return;
    }
    SGInstructionsPageManagement::instructionspagebackground = new SGWidget000221103(SGCentralManagement::mainbackground, 0.0f, 0.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateinstructionspage, SGInstructionsPageManagement::instructionspagebackground, &SGWidget000221103::ResizeObj);
    SGInstructionsPageManagement::continuebutton = new SGTextButton022211332(SGInstructionsPageManagement::instructionspagebackground, "continue", 0.0f, 1.0f, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateinstructionspage, SGInstructionsPageManagement::continuebutton, &SGTextButton022211332::ResizeObj);
    connect(SGInstructionsPageManagement::continuebutton, &SGTextButton022211332::clicked, &SGInstructionsPageManagement::tonextpage);
    SGInstructionsPageManagement::instructionspagescrollview = new SGScrollView000231100(SGInstructionsPageManagement::instructionspagebackground, 0.0f, 0.0f, 1.0f, -1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateinstructionspage, SGInstructionsPageManagement::instructionspagescrollview, &SGScrollView000231100::ResizeObj);
    SGInstructionsPageManagement::instructionspagelayout = new SGLayoutInstructionsPage(SGInstructionsPageManagement::instructionspagescrollview);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateinstructionspage, SGInstructionsPageManagement::instructionspagelayout, &SGLayoutInstructionsPage::ReceiveUpdateCall);
    (*SGInstructionsPageManagement::instructionspagescrollview).setWidget(SGInstructionsPageManagement::instructionspagelayout);
    (*SGInstructionsPageManagement::instructionspagelayout).ReceiveUpdateCall();
    QString infostring = "    After pressing the continue button, pls look at the circle that will be displayed on screen. Look at the center of the circle and do not blink. After the circle disappears in 20 seconds, continuing to look at the screen will allow you to see the impossible colour.";
    SGInstructionsPageManagement::instructionstext = new SGText011260021(SGInstructionsPageManagement::instructionspagelayout, infostring, 1.0f);
    connect(SGCentralManagement::signalsemitter, &SGSignalsEmitter::updateinstructionspage, SGInstructionsPageManagement::instructionstext, &SGText011260021::ResizeObj);
    SGGeneralLibrary::SetUIStyle(SGInstructionsPageManagement::instructionspagelayout, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour3);
}

void SGInstructionsPageManagement::tonextpage(){
    (*SGInstructionsPageManagement::instructionspagebackground).hide();
}
