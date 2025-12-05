#include <SGCLPDisplayPage.h>
#include <SGWBackground.h>
#include <SGWPageBackground.h>
#include <SGWWidget.h>
#include <SGXTimer.h>
#include <SGWBlankWidget.h>
#include <SGCLPOptionsPage.h>
#include <SGRRendererWidget.h>
#include <SGCLPCircleDisplay.h>
#include <SGCLPPolygonDisplay.h>
#include <SGCLPStarDisplay.h>

SGWBackground* SGCLPDisplayPage::instance = nullptr;
int SGCLPDisplayPage::time = 0;
SGXTimer* SGCLPDisplayPage::timer = nullptr;
SGWWidget* SGCLPDisplayPage::progressBar = nullptr;

SGWBackground* SGCLPDisplayPage::initialise(){
    SGWBackground* bg = new SGWPageBackground(SGWWidget::parentWidget, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 8);
    SGCLPDisplayPage::time = 0;
    SGCLPDisplayPage::progressBar = new SGWBlankWidget(bg, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 6);
    SGCLPDisplayPage::timer = new SGXTimer(1.0f, &SGCLPDisplayPage::updateProgressBar);
    if(SGCLPOptionsPage::chosenPattern == SGCLPOptionsPage::Circle){new SGRRendererWidget(bg, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, new SGCLPCircleDisplay(SGCLPOptionsPage::chosenBackgroundColour), nullptr);}
    else if(SGCLPOptionsPage::chosenPattern == SGCLPOptionsPage::Polygon){
        SGWBlankWidget* w = new SGWBlankWidget(bg, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, -1);
        (*w).setColour(SGCLPOptionsPage::chosenBackgroundColour);
        new SGRRendererWidget(bg, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, new SGCLPPolygonDisplay(SGCLPOptionsPage::chosenVertexCount, SGCLPOptionsPage::chosenForegroundColour), nullptr);
    }
    else if(SGCLPOptionsPage::chosenPattern == SGCLPOptionsPage::Star){
        SGWBlankWidget* w = new SGWBlankWidget(bg, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, -1);
        (*w).setColour(SGCLPOptionsPage::chosenBackgroundColour);
        new SGRRendererWidget(bg, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, new SGCLPStarDisplay(SGCLPOptionsPage::chosenVertexCount, SGCLPOptionsPage::chosenForegroundColour), nullptr);
    }
    return bg;
}

void SGCLPDisplayPage::activate(){
    SGWBackground::enable(SGCLPDisplayPage::instance, &SGCLPDisplayPage::initialise, nullptr);
}

void SGCLPDisplayPage::updateProgressBar(){
    SGCLPDisplayPage::time++;
    (*SGCLPDisplayPage::progressBar).setW1(static_cast<float>(SGCLPDisplayPage::time) / 10.0f);
    if(SGCLPDisplayPage::time == 10){
        SGCLPDisplayPage::time = 0;
        (*SGCLPDisplayPage::timer).deleteTimer();
        SGCLPDisplayPage::progressBar = nullptr;
        SGCLPDisplayPage::timer = nullptr;
        SGWBackground::disable(SGCLPDisplayPage::instance);
        SGCLPOptionsPage::activate();
    }
}
