#include "sgsignalsemitter.h"
#include "sgintropagemanagement.h"
#include "sgselectpagemanagement.h"

SGSignalsEmitter::SGSignalsEmitter(){

}

void SGSignalsEmitter::sendsignals(){
    emit (*this).updatescreen();
    if(SGIntroPageManagement::intropagebackground != nullptr && (*SGIntroPageManagement::intropagebackground).isVisible()){emit (*this).updateintropage();}
    if(SGSelectPageManagement::selectpagebackground != nullptr && (*SGSelectPageManagement::selectpagebackground).isVisible()){emit (*this).updateselectpage();}
}
