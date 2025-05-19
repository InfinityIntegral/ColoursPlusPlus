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
    bool x = (*obj).autoFillBackground();
    (*obj).setStyleSheet(s);
    (*obj).setAutoFillBackground(x);
}

void SGGeneralLibrary::updatefontsize(QWidget *obj){
    QString s = QString::number((*obj).size().height()) + QString("px");
    SGGeneralLibrary::SetUIStyle(obj, SGGeneralLibrary::stylesheetfieldfontsize, s);
}

QString SGGeneralLibrary::ColourUintToCSS(uint c){
    return ("rgba(" + QString::number(0xFF & (c >> 24)) + ", " + QString::number(0xFF & (c >> 16)) + ", " + QString::number(0xFF & (c >> 8)) + "," + QString::number(0xFF & c) + ")");
}

uint SGGeneralLibrary::ColourCSSToUint(QString &s){
    int x = 0;
    uint r = 0;
    uint g = 0;
    uint b = 0;
    uint a = 0;
    QString ts = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){ts += s[i];}
        else if(x == 0 && ts != ""){
            r = ts.toUInt();
            x++;
            ts = "";
        }
        else if(x == 1 && ts != ""){
            g = ts.toUInt();
            x++;
            ts = "";
        }
        else if(x == 2 && ts != ""){
            b = ts.toUInt();
            x++;
            ts = "";
        }
        else if(x == 3 && ts != ""){
            a = ts.toUInt();
            x++;
            ts = "";
        }
    }
    uint ans = (r << 24) | (g << 16) | (b << 8) | a;
    return ans;
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

uint SGGeneralLibrary::maxsaturatedcolour(float hue){
    hue -= 20.0f / 153.0f;
    if(hue < 0.0f){hue += 1.0f;}
    else if(hue > 1.0f){hue -= 1.0f;}
    float r;
    float g;
    float b;
    if(hue < 1.0f / 6.0f){
        r = 1.0f;
        g = 6.0f * hue;
        b = 0.0f;
    }
    else if(hue < 2.0f / 6.0f){
        r = 1.0f - 6.0f * (hue - 1.0f / 6.0f);
        g = 1.0f;
        b = 0.0f;
    }
    else if(hue < 3.0f / 6.0f){
        r = 0.0f;
        g = 1.0f;
        b = 6.0f * (hue - 2.0f / 6.0f);
    }
    else if(hue < 4.0f / 6.0f){
        r = 0.0f;
        g = 1.0f - 6.0f * (hue - 3.0f / 6.0f);
        b = 1.0f;
    }
    else if(hue < 5.0f / 6.0f){
        r = 6.0f * (hue - 4.0f / 6.0f);
        g = 0.0f;
        b = 1.0f;
    }
    else{
        r = 1.0f;
        g = 0.0f;
        b = 1.0f - 6.0f * (hue - 5.0f / 6.0f);
    }
    return ((((int)(255.0f * r)) << 24) | (((int)(255.0f * g)) << 16) | (((int)(255.0f * b)) << 8) | 0xFF);
}
