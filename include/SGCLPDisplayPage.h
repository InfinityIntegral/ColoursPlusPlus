#ifndef SGCLPDISPLAYPAGE_H
#define SGCLPDISPLAYPAGE_H

class SGWBackground;
class SGCLPDisplayPage {
public:
    static SGWBackground* instance;
    static SGWBackground* initialise();
    static void activate();
};

#endif // SGCLPDISPLAYPAGE_H
