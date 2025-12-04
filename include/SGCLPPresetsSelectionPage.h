#ifndef SGCLPPRESETSSELECTIONPAGE_H
#define SGCLPPRESETSSELECTIONPAGE_H

class SGWBackground;
class SGWWidget;
class SGXString;
class SGCLPPresetsSelectionPage{
public:
    static SGWBackground* instance;
    static SGWBackground* initialise();
    static void activate();
    static SGWWidget* listBackground;
    static void cancelPresetSelection();
    static void useSavedPreset(const SGXString& filePath);
};

#endif // SGCLPPRESETSSELECTIONPAGE_H
