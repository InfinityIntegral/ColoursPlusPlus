#include "sggenerallibrary.h"
#include <QWidget>
#include <QRegularExpression>
#include "sgcentralmanagement.h"

QString SGGeneralLibrary::stylesheetfieldbackgroundcolour = QString("background-color");
QString SGGeneralLibrary::stylesheetfieldtextcolour = QString("color");
QString SGGeneralLibrary::stylesheetfieldfontsize = QString("font-size");
QString SGGeneralLibrary::stylesheetfieldborder = QString("border");
QString SGGeneralLibrary::stylesheetfieldselectedbackgroundcolour = QString("selection-background-color");
QString SGGeneralLibrary::stylesheetfieldselectedtextcolour = QString("selection-color");
QString SGGeneralLibrary::stylesheetfieldscrollbarwidth = QString("width");
QString SGGeneralLibrary::stylesheetnoborder = QString("none");
QFont* SGGeneralLibrary::SingScriptSG = nullptr;
float SGGeneralLibrary::plusinf = std::numeric_limits<float>::infinity();
float SGGeneralLibrary::minusinf = (-1.0f) * std::numeric_limits<float>::infinity();

void SGGeneralLibrary::SetUIStyle(QWidget* obj, QString& k, QString& v){
    QString s = (*obj).styleSheet();
    QRegularExpression r(k + ":[^;]+;");
    if(s.contains(r)){s.replace(r, k + ": " + v + "; ");}
    else{s += (k + ": " + v + "; ");}
    (*obj).setStyleSheet(s);
}

void SGGeneralLibrary::updatefontsize(QWidget *obj){
    QString s = QString::number((*obj).size().height()) + QString("px");
    SGGeneralLibrary::SetUIStyle(obj, SGGeneralLibrary::stylesheetfieldfontsize, s);
}

QString SGGeneralLibrary::ColourUintToCSS(uint c){
    return ("rgba(" + QString::number(0xFF & (c >> 24)) + ", " + QString::number(0xFF & (c >> 16)) + ", " + QString::number(0xFF & (c >> 8)) + "," + QString::number(0xFF & c) + ")");
}

void SGGeneralLibrary::setscrollviewstylesheet(QWidget *obj){
    (*obj).setStyleSheet((R"(
        QScrollBar:vertical{
            width: 20px;
        }
        QScrollBar::handle:vertical{
            background: )" + SGCentralManagement::colour1 + R"(;
        }
        QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical{
            background: )" + SGCentralManagement::colour3 + R"(;
        }
    )"));
}

void SGGeneralLibrary::updatescrollbarwidth(QWidget *obj){
    QString s = QString::number(2.0f / 3.0f * SGCentralManagement::sizeunit) + "px";
    SGGeneralLibrary::SetUIStyle(obj, SGGeneralLibrary::stylesheetfieldscrollbarwidth, s);
}
