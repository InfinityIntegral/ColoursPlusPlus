#include "sgexplainpagemanagement.h"
#include "sgcentralmanagement.h"
#include "sggenerallibrary.h"
#include "sgintropagemanagement.h"

SGWidget000221103* SGExplainPageManagement::explainpagebackground = nullptr;
SGTextButton022211332* SGExplainPageManagement::restartbutton = nullptr;

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
}

void SGExplainPageManagement::restartapp(){
    (*SGExplainPageManagement::explainpagebackground).hide();
    SGIntroPageManagement::initialiseintropage();
}
