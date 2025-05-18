#include "sglayoutselectpage.h"
#include "sgselectpagemanagement.h"
#include "sgcentralmanagement.h"

SGLayoutSelectPage::SGLayoutSelectPage(QWidget *parent){
    (*this).setParent(parent);
    (*this).show();
    (*this).ReceiveUpdateCall();
}

void SGLayoutSelectPage::ReceiveUpdateCall(){
    (*this).move(QPoint(0.0f, 0.0f));
    QTimer::singleShot(0, this, &SGLayoutSelectPage::ResizeObj);
}

void SGLayoutSelectPage::ResizeObj(){
    float x = 0.0f;
    float y = 0.0f;
    float w = (*parentWidget()).size().width() / SGCentralManagement::sizeunit;
    (*SGSelectPageManagement::typeprompt).move(QPoint(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
    y += 1.5f;
    (*SGSelectPageManagement::stygianbutton).move(QPoint(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
    x += 3.0f;
    if(w - x < 4.5f){
        x = 0.0f;
        y += 1.0f;
    }
    (*SGSelectPageManagement::selfluminousbutton).move(QPoint(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
    x += 5.0f;
    if(w - x < 3.5f){
        x = 0.0f;
        y += 1.0f;
    }
    (*SGSelectPageManagement::hyperbolicbutton).move(QPoint(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
    x = 0.0f;
    y += 1.5f;
    (*SGSelectPageManagement::hueprompt).move(QPoint(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
    y += 1.5f;
    (*SGSelectPageManagement::hueselector).move(QPoint(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
    y += 2.4f;
    (*this).resize(QSize(w * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
}
