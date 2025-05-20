#ifndef SGESTIMATERGBMANAGEMENT_H
#define SGESTIMATERGBMANAGEMENT_H

#include <QObject>

class SGEstimateRGBManagement : public QObject
{
    Q_OBJECT
public:
    static QString EstimateRGBs();
private:
    SGEstimateRGBManagement(){}
    ~SGEstimateRGBManagement(){}
};

#endif // SGESTIMATERGBMANAGEMENT_H
