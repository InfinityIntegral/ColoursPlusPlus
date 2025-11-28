#ifndef SGCLPINTRODUCTIONPAGE_H
#define SGCLPINTRODUCTIONPAGE_H

class SGWBackground;
class SGCLPIntroductionPage {
public:
    static SGWBackground* instance;
    static SGWBackground* initialise();
    static void activate();
    static void terminate();
};

#endif // SGCLPINTRODUCTIONPAGE_H
