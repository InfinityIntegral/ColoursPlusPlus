#include <SGEXTN_EntryPoint.h>
#include <SGXCentral.h>

void init(){
    SGXCentral::applicationName = "Colours++ - a SGEXTN demo app";
    SGXCentral::applicationVersion = "v2.0.0";
    SGXCentral::organisationName = "05524F.sg (Singapore)";
    SGXCentral::folderName = "ColoursPlusPlus";
}

int main(int argc, char** argv){
    return SGEXTN(argc, argv, &init);
}
