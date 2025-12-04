#ifndef SGCLPOPTIONSPAGE_H
#define SGCLPOPTIONSPAGE_H

#include <SGXColourRGBA.h>

class SGWColourPickerWidget;
class SGWButton;
class SGWInput;
class SGWBackground;
class SGWWidget;
class SGCLPOptionsPage {
public:
    static SGWBackground* instance;
    static SGWBackground* initialise();
    static void activate();
    static SGWColourPickerWidget* foregroundColourPicker;
    static SGWButton* backgroundUseCustomButton;
    static SGWColourPickerWidget* backgroundColourPicker;
    static SGWButton* backgroundUseComplementaryButton;
    static SGWButton* backgroundComplementaryHueButton;
    static SGWButton* backgroundComplementarySaturationButton;
    static SGWButton* backgroundComplementaryLightnessButton;
    static SGWButton* patternCircleButton;
    static SGWButton* patternPolygonButton;
    static SGWButton* patternStarButton;
    static SGWButton* patternFractalButton;
    static SGWInput* polygonSideCountInput;
    static void reset();
    static void backgroundUseCustom();
    static void backgroundUseComplementary();
    static void backgroundComplementaryChannelToggle(SGWButton* x);
    static void patternSelect(SGWButton* x);
    static SGWWidget* polygonSideCountWarning;
    static void polygonSideCountCheck();
    static bool checkOptions();
    static void submitOptions();
    static SGXColourRGBA chosenBackgroundColour;
    static SGXColourRGBA chosenForegroundColour;
    enum Pattern{
        Circle,
        Polygon,
        Star,
        Fractal
    };
    static Pattern chosenPattern;
    static int chosenVertexCount;
    static void savePresets();
};

#endif // SGCLPOPTIONSPAGE_H
