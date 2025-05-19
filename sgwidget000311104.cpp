#include "sgwidget000311104.h"
#include "sgcentralmanagement.h"
#include "sggenerallibrary.h"

SGWidget000311104::SGWidget000311104(QWidget *parent, float x, float y, float w1, float w0, float h){
    (*this).setParent(parent);
    (*this).x = x;
    (*this).y = y;
    (*this).w1 = w1;
    (*this).w0 = w0;
    (*this).h = h;
    (*this).show();
    SGGeneralLibrary::SetUIStyle(this, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour3);
    (*this).setAutoFillBackground(true);
    (*this).ResizeObj();
}

void SGWidget000311104::ResizeObj(){
    (*this).move(QPoint(x * SGCentralManagement::sizeunit, y * SGCentralManagement::sizeunit));
    (*this).resize(QSize(w1 * (*parentWidget()).size().width() + w0 * SGCentralManagement::sizeunit, h * SGCentralManagement::sizeunit));
}
