#ifndef SGTEXT_2211__21_H
#define SGTEXT_2211__21_H

#include <QWidget>
#include <QLabel>

class SGText022110021 : public QLabel
{
    Q_OBJECT
public:
    SGText022110021(QWidget* parent, QString s, float w, float h);
    float w;
    float h;
public slots:
    void ResizeObj();
};

#endif // SGTEXT_2211__21_H
