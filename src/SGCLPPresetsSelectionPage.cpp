#include <SGCLPPresetsSelectionPage.h>
#include <SGWBackground.h>
#include <SGWWidget.h>
#include <SGWPageBackground.h>
#include <SGWScrollView.h>
#include <SGWTextButton.h>
#include <SGXString.h>
#include <SGCLPOptionsPage.h>
#include <SGXFileSystem.h>
#include <SGXFile.h>
#include <SGLArray.h>
#include <SGCLPDisplayPage.h>

SGWBackground* SGCLPPresetsSelectionPage::instance = nullptr;
SGWWidget* SGCLPPresetsSelectionPage::listBackground = nullptr;

SGWBackground* SGCLPPresetsSelectionPage::initialise(){
    SGWBackground* bg = new SGWPageBackground(SGWWidget::parentWidget, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 8);
    SGWScrollView* scrollView = new SGWScrollView(bg, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.5f, 8);
    SGCLPPresetsSelectionPage::listBackground = scrollView;
    new SGWTextButton(bg, "cancel", &SGCLPPresetsSelectionPage::cancelPresetSelection, 0.0f, 0.0f, 1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f);
    SGLArray<SGXString> filesList = SGXFileSystem::getFilesListWithExtension(SGXFileSystem::userDataFilePath, "sg");
    (*scrollView).setI0(static_cast<float>(filesList.length()));
    for(int i=0; i<filesList.length(); i++){
        SGWButton* button = new SGWTextButton(scrollView, SGXFileSystem::getFileNameNoExtension(filesList.at(i)), nullptr, 0.0f, 0.0f, 0.0f, static_cast<float>(i), 1.0f, 0.0f, 0.0f, 1.0f);
        (*button).attachedString = filesList.at(i);
        (*button).clickFunctionWithString = &SGCLPPresetsSelectionPage::useSavedPreset;
    }
    return bg;
}

void SGCLPPresetsSelectionPage::activate(){
    SGWBackground::enable(SGCLPPresetsSelectionPage::instance, &SGCLPPresetsSelectionPage::initialise, nullptr);
}

void SGCLPPresetsSelectionPage::cancelPresetSelection(){
    SGWBackground::disable(SGCLPPresetsSelectionPage::instance);
}

void SGCLPPresetsSelectionPage::useSavedPreset(const SGXString &filePath){
    const SGXFile file(filePath, SGXFile::ReadOnly);
    SGCLPOptionsPage::chosenForegroundColour = file.readColourRGBA();
    SGCLPOptionsPage::chosenBackgroundColour = file.readColourRGBA();
    const int patternIndex = file.readInt();
    if(patternIndex == 1){SGCLPOptionsPage::chosenPattern = SGCLPOptionsPage::Circle;}
    else if(patternIndex == 2){SGCLPOptionsPage::chosenPattern = SGCLPOptionsPage::Polygon;}
    else if(patternIndex == 3){SGCLPOptionsPage::chosenPattern = SGCLPOptionsPage::Star;}
    else{SGCLPOptionsPage::chosenPattern = SGCLPOptionsPage::Fractal;}
    SGCLPOptionsPage::chosenVertexCount = file.readInt();
    SGWBackground::disable(SGCLPPresetsSelectionPage::instance);
    SGWBackground::disable(SGCLPOptionsPage::instance);
    SGCLPDisplayPage::activate();
}
