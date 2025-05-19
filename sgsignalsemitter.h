#ifndef SGSIGNALSEMITTER_H
#define SGSIGNALSEMITTER_H

#include <QObject>

class SGSignalsEmitter : public QObject
{
    Q_OBJECT
public:
    SGSignalsEmitter();
    void sendsignals();
signals:
    void updatescreen();
    void updateintropage();
    void updateselectpage();
    void updateinstructionspage();
    void updateillusionpage();
    void updateexplainpage();
};

#endif // SGSIGNALSEMITTER_H
