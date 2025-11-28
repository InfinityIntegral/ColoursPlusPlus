#include <SGCLPDisplayPage.h>
#include <SGWBackground.h>
#include <SGWPageBackground.h>
#include <SGWWidget.h>

SGWBackground* SGCLPDisplayPage::instance = nullptr;

SGWBackground* SGCLPDisplayPage::initialise(){
    return new SGWPageBackground(SGWWidget::parentWidget, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 8);
}

void SGCLPDisplayPage::activate(){
    SGWBackground::enable(SGCLPDisplayPage::instance, &SGCLPDisplayPage::initialise, nullptr);
}
