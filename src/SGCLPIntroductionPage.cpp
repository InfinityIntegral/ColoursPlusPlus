#include <SGCLPIntroductionPage.h>
#include <SGWBackground.h>
#include <SGXString.h>
#include <SGXChar.h>
#include <SGWWidget.h>
#include <SGWPageBackground.h>
#include <SGWLongLabel.h>
#include <SGWTextButton.h>
#include <SGCLPOptionsPage.h>

SGWBackground* SGCLPIntroductionPage::instance = nullptr;

SGWBackground* SGCLPIntroductionPage::initialise(){
    SGXString message = "This is ColoursPlusPlus, kind of demo app for SGEXTN that we will be building in this tutorial. The app will showcase various SGEXTN features including the SGWidget and SG - RI systems used to implement interactive and customisable user interfaces.";
    message += " ";
    message += SGXChar(0x0378);
    SGWPageBackground* bg = new SGWPageBackground(SGWWidget::parentWidget, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f);
    new SGWLongLabel(bg, message, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.5f, 0.0f, 0.5f);
    new SGWTextButton(bg, "continue", &SGCLPIntroductionPage::terminate, 0.0f, 0.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f);
    return bg;
}

void SGCLPIntroductionPage::activate(){
    SGWBackground::enable(SGCLPIntroductionPage::instance, &SGCLPIntroductionPage::initialise, nullptr);
}

void SGCLPIntroductionPage::terminate(){
    SGWBackground::disable(SGCLPIntroductionPage::instance);
    SGCLPOptionsPage::activate();
}
