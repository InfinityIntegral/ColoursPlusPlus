#include "sgtext011260021.h"
#include "sggenerallibrary.h"
#include "sgcentralmanagement.h"

SGText011260021::SGText011260021(QWidget *parent, QString s, float fs){
    (*this).setParent(parent);
    (*this).fs = fs;
    (*this).show();
    (*this).setAlignment(Qt::AlignLeft | Qt::AlignTop);
    (*this).setFont(*SGGeneralLibrary::SingScriptSG);
    (*this).setWordWrap(true);
    SGGeneralLibrary::SetUIStyle(this, SGGeneralLibrary::stylesheetfieldtextcolour, SGCentralManagement::colour1);
    SGGeneralLibrary::SetUIStyle(this, SGGeneralLibrary::stylesheetfieldbackgroundcolour, SGCentralManagement::colour0);
    (*this).setAutoFillBackground(true);
    (*this).setText(s);
    (*this).ResizeObj();
}

void SGText011260021::ResizeObj(){
    QString fss = QString::number(fs * SGCentralManagement::sizeunit) + "px";
    SGGeneralLibrary::SetUIStyle(this, SGGeneralLibrary::stylesheetfieldfontsize, fss);
    (*this).resize(QSize((*parentWidget()).size().width(), (*this).heightForWidth((*parentWidget()).size().width())));
}
