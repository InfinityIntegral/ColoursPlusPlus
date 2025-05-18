#ifndef SGLAYOUTINTROPAGE_H
#define SGLAYOUTINTROPAGE_H

#include <QWidget>

class SGLayoutIntroPage : public QWidget
{
    Q_OBJECT
public:
    SGLayoutIntroPage(QWidget *parent);
public slots:
    void ReceiveUpdateCall();
    void ResizeObj();
};

#endif // SGLAYOUTINTROPAGE_H
