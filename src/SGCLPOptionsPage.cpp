#include <SGCLPOptionsPage.h>
#include <SGWBackground.h>
#include <SGWWidget.h>
#include <SGWScrollView.h>
#include <SGWTextLabel.h>
#include <SGWHorizontalAlignment.h>
#include <SGWTextButton.h>
#include <SGWColourPickerWidget.h>
#include <SGXColourRGBA.h>
#include <SGWTextInput.h>
#include <SGLIntLimits.h>
#include <SGWNotify.h>
#include <SGXColourHSLA.h>
#include <SGCLPDisplayPage.h>

SGWBackground* SGCLPOptionsPage::instance = nullptr;
SGWColourPickerWidget* SGCLPOptionsPage::foregroundColourPicker = nullptr;
SGWButton* SGCLPOptionsPage::backgroundUseCustomButton = nullptr;
SGWColourPickerWidget* SGCLPOptionsPage::backgroundColourPicker = nullptr;
SGWButton* SGCLPOptionsPage::backgroundUseComplementaryButton = nullptr;
SGWButton* SGCLPOptionsPage::backgroundComplementaryHueButton = nullptr;
SGWButton* SGCLPOptionsPage::backgroundComplementarySaturationButton = nullptr;
SGWButton* SGCLPOptionsPage::backgroundComplementaryLightnessButton = nullptr;
SGWButton* SGCLPOptionsPage::patternCircleButton = nullptr;
SGWButton* SGCLPOptionsPage::patternPolygonButton = nullptr;
SGWButton* SGCLPOptionsPage::patternStarButton = nullptr;
SGWButton* SGCLPOptionsPage::patternFractalButton = nullptr;
SGWInput* SGCLPOptionsPage::polygonSideCountInput = nullptr;
SGWWidget* SGCLPOptionsPage::polygonSideCountWarning = nullptr;

SGXColourRGBA SGCLPOptionsPage::chosenForegroundColour = SGXColourRGBA(255, 0, 200);
SGXColourRGBA SGCLPOptionsPage::chosenBackgroundColour = SGXColourRGBA(255, 255, 255);
SGCLPOptionsPage::Pattern SGCLPOptionsPage::chosenPattern = SGCLPOptionsPage::Circle;
int SGCLPOptionsPage::chosenVertexCount = 3;

void SGCLPOptionsPage::activate(){
    SGWBackground::enable(SGCLPOptionsPage::instance, &SGCLPOptionsPage::initialise, &SGCLPOptionsPage::reset);
}

SGWBackground* SGCLPOptionsPage::initialise(){
    SGWBackground* bg = new SGWScrollView(SGWWidget::parentWidget, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 20.0f, 0.0f, 0.5f, 8);
    new SGWTextLabel(bg, "Preferences", 0.0f, 0.5f, 0.0f, 0.5f, 1.0f, -1.0f, 0.0f, 1.5f, SGWHorizontalAlignment::Center, false);
    new SGWTextButton(bg, "use preset", nullptr, 0.0f, 0.5f, 0.0f, 2.5f, 1.0f, -1.0f, 0.0f, 1.0f);
    new SGWTextLabel(bg, "foreground colour:", 0.0f, 0.5f, 0.0f, 4.5f, 0.5f, -0.6f, 0.0f, 1.0f, SGWHorizontalAlignment::Right, false);
    SGCLPOptionsPage::foregroundColourPicker = new SGWColourPickerWidget(bg, 0.5f, 0.1f, 0.0f, 4.5f, 0.5f, -0.6f, 0.0f, 1.0f, SGXColourRGBA(255, 0, 200));
    new SGWTextLabel(bg, "background colour (choose from below)", 0.0f, 0.5f, 0.0f, 6.0f, 1.0f, -1.0f, 0.0f, 1.0f, SGWHorizontalAlignment::Center, false);
    SGCLPOptionsPage::backgroundColourPicker = new SGWColourPickerWidget(bg, 0.5f, 0.0f, 0.0f, 7.5f, 0.5f, -0.5f, 0.0f, 1.0f, SGXColourRGBA(255, 255, 255));
    SGCLPOptionsPage::backgroundUseCustomButton = new SGWTextButton(bg, "custom", &SGCLPOptionsPage::backgroundUseCustom, 0.0f, 0.5f, 0.0f, 7.5f, 0.5f, -0.5f, 0.0f, 1.0f);
    SGCLPOptionsPage::backgroundComplementaryHueButton = new SGWTextButton(bg, "H", nullptr, 0.5f, 0.0f, 0.0f, 8.5f, 1.0f / 6.0f, -1.0f / 6.0f, 0.0f, 1.0f);
    (*SGCLPOptionsPage::backgroundComplementaryHueButton).clickFunctionWithPointer = &SGCLPOptionsPage::backgroundComplementaryChannelToggle;
    SGCLPOptionsPage::backgroundComplementarySaturationButton = new SGWTextButton(bg, "S", nullptr, 2.0f / 3.0f, -1.0f / 6.0f, 0.0f, 8.5f, 1.0f / 6.0f, -1.0f / 6.0f, 0.0f, 1.0f);
    (*SGCLPOptionsPage::backgroundComplementarySaturationButton).clickFunctionWithPointer = &SGCLPOptionsPage::backgroundComplementaryChannelToggle;
    SGCLPOptionsPage::backgroundComplementaryLightnessButton = new SGWTextButton(bg, "L", nullptr, 5.0f / 6.0f, -1.0f / 3.0f, 0.0f, 8.5f, 1.0f / 6.0f, -1.0f / 6.0f, 0.0f, 1.0f);
    (*SGCLPOptionsPage::backgroundComplementaryLightnessButton).clickFunctionWithPointer = &SGCLPOptionsPage::backgroundComplementaryChannelToggle;
    SGCLPOptionsPage::backgroundUseComplementaryButton = new SGWTextButton(bg, "complementary", &SGCLPOptionsPage::backgroundUseComplementary, 0.0f, 0.5f, 0.0f, 8.5f, 1.0f, -1.0f, 0.0f, 1.0f);
    new SGWTextLabel(bg, "choose pattern", 0.0f, 0.5f, 0.0f, 10.5f, 1.0f, -1.0f, 0.0f, 1.0f, SGWHorizontalAlignment::Center, false);
    SGCLPOptionsPage::patternCircleButton = new SGWTextButton(bg, "circle", nullptr, 0.0f, 0.5f, 0.0f, 12.0f, 0.5f, -0.5f, 0.0f, 1.0f);
    (*SGCLPOptionsPage::patternCircleButton).clickFunctionWithPointer = &SGCLPOptionsPage::patternSelect;
    (*SGCLPOptionsPage::patternCircleButton).attachedInt = 0;
    SGCLPOptionsPage::patternPolygonButton = new SGWTextButton(bg, "regular polygon", nullptr, 0.5f, 0.0f, 0.0f, 12.0f, 0.5f, -0.5f, 0.0f, 1.0f);
    (*SGCLPOptionsPage::patternPolygonButton).clickFunctionWithPointer = &SGCLPOptionsPage::patternSelect;
    (*SGCLPOptionsPage::patternPolygonButton).attachedInt = 1;
    SGCLPOptionsPage::patternStarButton = new SGWTextButton(bg, "star", nullptr, 0.0f, 0.5f, 0.0f, 13.0f, 0.5f, -0.5f, 0.0f, 1.0f);
    (*SGCLPOptionsPage::patternStarButton).clickFunctionWithPointer = &SGCLPOptionsPage::patternSelect;
    (*SGCLPOptionsPage::patternStarButton).attachedInt = 1;
    SGCLPOptionsPage::patternFractalButton = new SGWTextButton(bg, "fractal", nullptr, 0.5f, 0.0f, 0.0f, 13.0f, 0.5f, -0.5f, 0.0f, 1.0f);
    (*SGCLPOptionsPage::patternFractalButton).clickFunctionWithPointer = &SGCLPOptionsPage::patternSelect;
    (*SGCLPOptionsPage::patternFractalButton).attachedInt = 0;
    new SGWTextLabel(bg, "number of vertices:", 0.0f, 0.5f, 0.0f, 14.5f, 0.5f, -0.6f, 0.0f, 1.0f, SGWHorizontalAlignment::Right, false);
    new SGWTextLabel(bg, "(not applicable)", 0.5f, 0.1f, 0.0f, 14.5f, 0.5f, -0.6f, 0.0f, 1.0f, SGWHorizontalAlignment::Left, false);
    SGCLPOptionsPage::polygonSideCountInput = new SGWTextInput(bg, &SGCLPOptionsPage::polygonSideCountCheck, 0.5f, 0.1f, 0.0f, 14.5f, 0.5f, -0.6f, 0.0f, 1.0f);
    SGCLPOptionsPage::polygonSideCountWarning = new SGWTextLabel(bg, "integer 3 or above", 0.5f, 0.1f, 0.0f, 15.5f, 0.5f, -0.6f, 0.0f, 0.75f, SGWHorizontalAlignment::Left, true);
    new SGWTextButton(bg, "save current settings as preset", nullptr, 0.0f, 0.5f, 0.0f, 17.0f, 1.0f, -1.0f, 0.0f, 1.0f);
    new SGWTextButton(bg, "save preferences and continue", &SGCLPOptionsPage::submitOptions, 0.0f, 0.5f, 0.0f, 18.5f, 1.0f, -1.0f, 0.0f, 1.0f);
    return bg;
}

void SGCLPOptionsPage::reset(){
    SGCLPOptionsPage::backgroundUseCustom();
    (*SGCLPOptionsPage::backgroundComplementaryHueButton).setSelected(false);
    (*SGCLPOptionsPage::backgroundComplementarySaturationButton).setSelected(false);
    (*SGCLPOptionsPage::backgroundComplementaryLightnessButton).setSelected(true);
    SGCLPOptionsPage::patternSelect(SGCLPOptionsPage::patternCircleButton);
    (*SGCLPOptionsPage::polygonSideCountInput).setTextFromInt(3);
}

void SGCLPOptionsPage::backgroundUseCustom(){
    if((*SGCLPOptionsPage::backgroundUseCustomButton).getSelected() == true){return;}
    (*SGCLPOptionsPage::backgroundUseCustomButton).setSelected(true);
    (*SGCLPOptionsPage::backgroundUseComplementaryButton).setSelected(false);
    (*SGCLPOptionsPage::backgroundUseCustomButton).setW1(0.5f);
    (*SGCLPOptionsPage::backgroundUseCustomButton).setW0(-0.5f);
    (*SGCLPOptionsPage::backgroundUseComplementaryButton).setW1(1.0f);
    (*SGCLPOptionsPage::backgroundUseComplementaryButton).setW0(-1.0f);
}

void SGCLPOptionsPage::backgroundUseComplementary(){
    if((*SGCLPOptionsPage::backgroundUseComplementaryButton).getSelected() == true){return;}
    (*SGCLPOptionsPage::backgroundUseComplementaryButton).setSelected(true);
    (*SGCLPOptionsPage::backgroundUseCustomButton).setSelected(false);
    (*SGCLPOptionsPage::backgroundUseComplementaryButton).setW1(0.5f);
    (*SGCLPOptionsPage::backgroundUseComplementaryButton).setW0(-0.5f);
    (*SGCLPOptionsPage::backgroundUseCustomButton).setW1(1.0f);
    (*SGCLPOptionsPage::backgroundUseCustomButton).setW0(-1.0f);
}

void SGCLPOptionsPage::backgroundComplementaryChannelToggle(SGWButton *x){
    if((*x).getSelected() == true){(*x).setSelected(false);}
    else{(*x).setSelected(true);}
}

void SGCLPOptionsPage::patternSelect(SGWButton *x){
    (*SGCLPOptionsPage::patternCircleButton).setSelected(false);
    (*SGCLPOptionsPage::patternPolygonButton).setSelected(false);
    (*SGCLPOptionsPage::patternStarButton).setSelected(false);
    (*SGCLPOptionsPage::patternFractalButton).setSelected(false);
    (*x).setSelected(true);
    if((*x).attachedInt == 0){
        (*SGCLPOptionsPage::polygonSideCountInput).setItemVisibility(false);
        (*SGCLPOptionsPage::polygonSideCountWarning).setItemVisibility(false);
    }
    else{
        (*SGCLPOptionsPage::polygonSideCountInput).setItemVisibility(true);
        if((*SGCLPOptionsPage::polygonSideCountInput).getInvalid() == true){(*SGCLPOptionsPage::polygonSideCountWarning).setItemVisibility(true);}
    }
}

void SGCLPOptionsPage::polygonSideCountCheck(){
    bool isValid = true;
    (void)((*SGCLPOptionsPage::polygonSideCountInput).getTextAsInt(&isValid, 3, SGLIntLimits::maximum()));
    if(isValid == false){
        (*SGCLPOptionsPage::polygonSideCountInput).setInvalid(true);
        (*SGCLPOptionsPage::polygonSideCountWarning).setItemVisibility(true);
    }
    else{
        (*SGCLPOptionsPage::polygonSideCountInput).setInvalid(false);
        (*SGCLPOptionsPage::polygonSideCountWarning).setItemVisibility(false);
    }
}

void SGCLPOptionsPage::submitOptions(){
    if((*SGCLPOptionsPage::polygonSideCountInput).getInvalid() == true && ((*SGCLPOptionsPage::patternPolygonButton).getSelected() == true || (*SGCLPOptionsPage::patternStarButton).getSelected() == true)){
        SGWNotify::pullDownNotify("invalid number of vertices chosen");
        return;
    }
    SGCLPOptionsPage::chosenForegroundColour = (*SGCLPOptionsPage::foregroundColourPicker).getColour();
    SGCLPOptionsPage::chosenBackgroundColour = SGCLPOptionsPage::chosenForegroundColour;
    if((*SGCLPOptionsPage::backgroundUseCustomButton).getSelected() == true){SGCLPOptionsPage::chosenBackgroundColour = (*SGCLPOptionsPage::backgroundColourPicker).getColour();}
    else{
        SGXColourHSLA backgroundColourHSLA(SGCLPOptionsPage::chosenBackgroundColour);
        if((*SGCLPOptionsPage::backgroundComplementaryHueButton).getSelected() == true){backgroundColourHSLA.invertHue();}
        if((*SGCLPOptionsPage::backgroundComplementarySaturationButton).getSelected() == true){backgroundColourHSLA.invertSaturation();}
        if((*SGCLPOptionsPage::backgroundComplementaryLightnessButton).getSelected() == true){backgroundColourHSLA.invertLightness();}
        SGCLPOptionsPage::chosenBackgroundColour = backgroundColourHSLA.toRGBA();
    }
    if((*SGCLPOptionsPage::patternCircleButton).getSelected() == true){SGCLPOptionsPage::chosenPattern = SGCLPOptionsPage::Circle;}
    else if((*SGCLPOptionsPage::patternPolygonButton).getSelected() == true){SGCLPOptionsPage::chosenPattern = SGCLPOptionsPage::Polygon;}
    else if((*SGCLPOptionsPage::patternStarButton).getSelected() == true){SGCLPOptionsPage::chosenPattern = SGCLPOptionsPage::Star;}
    else{SGCLPOptionsPage::chosenPattern = SGCLPOptionsPage::Fractal;}
    SGCLPOptionsPage::chosenVertexCount = (*SGCLPOptionsPage::polygonSideCountInput).getTextAsInt(nullptr, 3, SGLIntLimits::maximum());
    SGWBackground::disable(SGCLPOptionsPage::instance);
    SGCLPDisplayPage::activate();
}
