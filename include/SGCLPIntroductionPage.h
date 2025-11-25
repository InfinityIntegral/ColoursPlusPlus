#ifndef SGCLPINTRODUCTIONPAGE_H
#define SGCLPINTRODUCTIONPAGE_H

class SGWBackground;
class SGCLPIntroductionPage {
public:
    static SGWBackground* instance;
    static SGWBackground* initialise();
    static void activate();
};

#endif // SGCLPINTRODUCTIONPAGE_H
