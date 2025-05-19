#ifndef SGWIDGET___3111_4_H
#define SGWIDGET___3111_4_H

#include <QWidget>

class SGWidget000311104 : public QWidget
{
    Q_OBJECT
public:
    SGWidget000311104(QWidget* parent, float x, float y, float w1, float w0, float h);
    float x;
    float y;
    float w1;
    float w0;
    float h;
public slots:
    void ResizeObj();
};

#endif // SGWIDGET___3111_4_H
