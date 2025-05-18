#ifndef SGLAYOUTSELECTPAGE_H
#define SGLAYOUTSELECTPAGE_H

#include <QWidget>

class SGLayoutSelectPage : public QWidget
{
    Q_OBJECT
public:
    SGLayoutSelectPage(QWidget* parent);
public slots:
    void ReceiveUpdateCall();
    void ResizeObj();
};

#endif // SGLAYOUTSELECTPAGE_H
