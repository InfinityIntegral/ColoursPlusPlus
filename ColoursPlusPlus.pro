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
    sgcomplementarycolourrenderer.cpp \
    sgexplainpagemanagement.cpp \
    sggenerallibrary.cpp \
    sghueselectrenderer.cpp \
    sgillusionmanagement.cpp \
    sginstructionspagemanagement.cpp \
    sgintropagemanagement.cpp \
    sglayoutinstructionspage.cpp \
    sglayoutintropage.cpp \
    sglayoutselectpage.cpp \
    sgrootwindow.cpp \
    sgscrollview000231100.cpp \
    sgselectpagemanagement.cpp \
    sgsignalsemitter.cpp \
    sgstatusbarmanagement.cpp \
    sgtext011260021.cpp \
    sgtext012110021.cpp \
    sgtext022110021.cpp \
    sgtext022221131.cpp \
    sgtextbutton022110032.cpp \
    sgtextbutton022211332.cpp \
    sgtextbutton022314332.cpp \
    sgwidget000221103.cpp \
    sgwidget000311104.cpp \
    sgwidget000411102.cpp \
    sgwidget000451103.cpp

HEADERS += \
    openglincludes.h \
    sgcentralmanagement.h \
    sgcomplementarycolourrenderer.h \
    sgexplainpagemanagement.h \
    sggenerallibrary.h \
    sghueselectrenderer.h \
    sgillusionmanagement.h \
    sginstructionspagemanagement.h \
    sgintropagemanagement.h \
    sglayoutinstructionspage.h \
    sglayoutintropage.h \
    sglayoutselectpage.h \
    sgrootwindow.h \
    sgscrollview000231100.h \
    sgselectpagemanagement.h \
    sgsignalsemitter.h \
    sgstatusbarmanagement.h \
    sgtext011260021.h \
    sgtext012110021.h \
    sgtext022110021.h \
    sgtext022221131.h \
    sgtextbutton022110032.h \
    sgtextbutton022211332.h \
    sgtextbutton022314332.h \
    sgwidget000221103.h \
    sgwidget000311104.h \
    sgwidget000411102.h \
    sgwidget000451103.h

RESOURCES += \
    assets.qrc
