#include "sglayoutintropage.h"
#include "sgintropagemanagement.h"
#include "sgcentralmanagement.h"

SGLayoutIntroPage::SGLayoutIntroPage(QWidget *parent){
    (*this).setParent(parent);
    (*this).show();
    (*this).ReceiveUpdateCall();
}

void SGLayoutIntroPage::ReceiveUpdateCall(){
    (*this).move(QPoint(0.0f, 0.0f));
    (*this).resize(QSize((*parentWidget()).size().width(), (*this).size().height()));
    QTimer::singleShot(0, this, &SGLayoutIntroPage::ResizeObj);
}

void SGLayoutIntroPage::ResizeObj(){
    float x = 0.0f;
    float y = 0.0f;
    float w = (*parentWidget()).size().width() / SGCentralManagement::sizeunit;
    x = 0.5f * w - 3.0f;
    (*SGIntroPageManagement::apptitle).move(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit);
    x = 0.0f;
    y += 2.0f;
    (*SGIntroPageManagement::infotext).move(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit);
    y += ((float)(*SGIntroPageManagement::infotext).size().height()) / SGCentralManagement::sizeunit;
    y += 0.5f;
    (*this).resize(QSize(w * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
}
