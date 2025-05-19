#include "sglayoutinstructionspage.h"
#include "sginstructionspagemanagement.h"
#include "sgcentralmanagement.h"

SGLayoutInstructionsPage::SGLayoutInstructionsPage(QWidget *parent){
    (*this).setParent(parent);
    (*this).show();
    (*this).ReceiveUpdateCall();
}

void SGLayoutInstructionsPage::ReceiveUpdateCall(){
    (*this).move(QPoint(0.0f, 0.0f));
    (*this).resize(QSize((*parentWidget()).size().width(), (*this).size().height()));
    QTimer::singleShot(0, this, &SGLayoutInstructionsPage::ResizeObj);
}

void SGLayoutInstructionsPage::ResizeObj(){
    float x = 0.0f;
    float y = 0.0f;
    float w = (*parentWidget()).size().width() / SGCentralManagement::sizeunit;
    (*SGInstructionsPageManagement::instructionstext).move(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit);
    y += ((float)(*SGInstructionsPageManagement::instructionstext).size().height()) / SGCentralManagement::sizeunit;
    y += 0.5f;
    (*this).resize(QSize(w * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
}
