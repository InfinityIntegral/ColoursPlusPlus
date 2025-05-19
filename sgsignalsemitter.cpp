#include "sgsignalsemitter.h"
#include "sgintropagemanagement.h"
#include "sgselectpagemanagement.h"
#include "sginstructionspagemanagement.h"
#include "sgillusionmanagement.h"
#include "sgexplainpagemanagement.h"

SGSignalsEmitter::SGSignalsEmitter(){

}

void SGSignalsEmitter::sendsignals(){
    emit (*this).updatescreen();
    if(SGIntroPageManagement::intropagebackground != nullptr && (*SGIntroPageManagement::intropagebackground).isVisible()){emit (*this).updateintropage();}
    if(SGSelectPageManagement::selectpagebackground != nullptr && (*SGSelectPageManagement::selectpagebackground).isVisible()){emit (*this).updateselectpage();}
    if(SGInstructionsPageManagement::instructionspagebackground != nullptr && (*SGInstructionsPageManagement::instructionspagebackground).isVisible()){emit (*this).updateinstructionspage();}
    if(SGIllusionManagement::illusionpagebackground != nullptr && (*SGIllusionManagement::illusionpagebackground).isVisible()){emit (*this).updateillusionpage();}
    if(SGExplainPageManagement::explainpagebackground != nullptr && (*SGExplainPageManagement::explainpagebackground).isVisible()){emit (*this).updateexplainpage();}
}
