TEMPLATE = app
TARGET = ColoursPlusPlus

QT = core gui widgets opengl openglwidgets

DISTFILES += \
    .gitignore \
    LICENSE.txt \
    README.md

SOURCES += \
    main.cpp \
    sgcentralmanagement.cpp \
    sggenerallibrary.cpp \
    sgintropagemanagement.cpp \
    sglayoutintropage.cpp \
    sgrootwindow.cpp \
    sgscrollview000231100.cpp \
    sgsignalsemitter.cpp \
    sgstatusbarmanagement.cpp \
    sgtext011260021.cpp \
    sgtext022110021.cpp \
    sgtext022221131.cpp \
    sgtextbutton022211332.cpp \
    sgwidget000221103.cpp \
    sgwidget000411102.cpp \
    sgwidget000451103.cpp

HEADERS += \
    sgcentralmanagement.h \
    sggenerallibrary.h \
    sgintropagemanagement.h \
    sglayoutintropage.h \
    sgrootwindow.h \
    sgscrollview000231100.h \
    sgsignalsemitter.h \
    sgstatusbarmanagement.h \
    sgtext011260021.h \
    sgtext022110021.h \
    sgtext022221131.h \
    sgtextbutton022211332.h \
    sgwidget000221103.h \
    sgwidget000411102.h \
    sgwidget000451103.h

RESOURCES += \
    assets.qrc
