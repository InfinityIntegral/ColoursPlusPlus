#ifndef SGTEXT_1126__21_H
#define SGTEXT_1126__21_H

#include <QWidget>
#include <QLabel>

class SGText011260021 : public QLabel
{
    Q_OBJECT
public:
    SGText011260021(QWidget* parent, QString s, float fs);
    float fs;
public slots:
    void ResizeObj();
};

#endif // SGTEXT_1126__21_H
