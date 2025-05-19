#include "sglayoutexplainpage.h"
#include "sgexplainpagemanagement.h"
#include "sgcentralmanagement.h"

SGLayoutExplainPage::SGLayoutExplainPage(QWidget *parent){
    (*this).setParent(parent);
    (*this).show();
    (*this).ReceiveUpdateCall();
}

void SGLayoutExplainPage::ReceiveUpdateCall(){
    (*this).move(QPoint(0.0f, 0.0f));
    (*this).resize(QSize((*parentWidget()).size().width(), (*this).size().height()));
    QTimer::singleShot(0, this, &SGLayoutExplainPage::ResizeObj);
}

void SGLayoutExplainPage::ResizeObj(){
    float x = 0.0f;
    float y = 0.0f;
    float w = (*parentWidget()).size().width() / SGCentralManagement::sizeunit;
    (*SGExplainPageManagement::explaintext).move(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit);
    y += (*SGExplainPageManagement::explaintext).size().height() / SGCentralManagement::sizeunit;
    y += 0.5f;
    (*SGExplainPageManagement::moreinfobutton).move(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit);
    y += 1.5f;
    (*this).resize(QSize(w * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
}
