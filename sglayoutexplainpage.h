#ifndef SGLAYOUTEXPLAINPAGE_H
#define SGLAYOUTEXPLAINPAGE_H

#include <QWidget>

class SGLayoutExplainPage : public QWidget
{
    Q_OBJECT
public:
    SGLayoutExplainPage(QWidget* parent);
public slots:
    void ReceiveUpdateCall();
    void ResizeObj();
};

#endif // SGLAYOUTEXPLAINPAGE_H
