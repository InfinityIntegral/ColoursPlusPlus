#ifndef SGLAYOUTINSTRUCTIONSPAGE_H
#define SGLAYOUTINSTRUCTIONSPAGE_H

#include <QWidget>

class SGLayoutInstructionsPage : public QWidget
{
    Q_OBJECT
public:
    SGLayoutInstructionsPage(QWidget* parent);
public slots:
    void ReceiveUpdateCall();
    void ResizeObj();
};

#endif // SGLAYOUTINSTRUCTIONSPAGE_H
