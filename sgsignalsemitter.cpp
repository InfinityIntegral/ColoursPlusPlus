#include "sgsignalsemitter.h"
#include "sgintropagemanagement.h"

SGSignalsEmitter::SGSignalsEmitter(){

}

void SGSignalsEmitter::sendsignals(){
    emit (*this).updatescreen();
    if(SGIntroPageManagement::intropagescrollview != nullptr && (*SGIntroPageManagement::intropagescrollview).isVisible()){emit (*this).updateintropage();}
}
