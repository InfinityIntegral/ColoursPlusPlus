#ifndef SGCLPDISPLAYPAGE_H
#define SGCLPDISPLAYPAGE_H

class SGWBackground;
class SGWWidget;
class SGXTimer;
class SGCLPDisplayPage {
public:
    static SGWBackground* instance;
    static SGWBackground* initialise();
    static void activate();
    static int time;
    static SGXTimer* timer;
    static SGWWidget* progressBar;
    static void updateProgressBar();
};

#endif // SGCLPDISPLAYPAGE_H
