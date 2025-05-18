#include "sghueselectrenderer.h"
#include "sgcentralmanagement.h"
#include "sgselectpagemanagement.h"
#include "sggenerallibrary.h"
#include <QEvent>
#include <QTouchEvent>

SGHueSelectRenderer::SGHueSelectRenderer(QWidget *parent){
    (*this).setParent(parent);
    (*this).show();
    (*this).ResizeObj();
}

SGHueSelectRenderer::~SGHueSelectRenderer(){
    makeCurrent();
    doneCurrent();
}

void SGHueSelectRenderer::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    (*this).setAttribute(Qt::WA_AcceptTouchEvents);

    vertexshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    (*vertexshader).compileSourceFile(":/assets/hueselect.vert");
    fragmentshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    (*fragmentshader).compileSourceFile(":/assets/hueselect.frag");
    shaderprogramme = new QOpenGLShaderProgram(this);
    (*shaderprogramme).addShader(vertexshader);
    (*shaderprogramme).addShader(fragmentshader);
    (*shaderprogramme).link();
    gvppointerposition = (*shaderprogramme).uniformLocation("pointerposition");
    gvprendertype = (*shaderprogramme).uniformLocation("rendertype");
    gvpcolour2 = (*shaderprogramme).uniformLocation("colour2");
    gvpcolour3 = (*shaderprogramme).uniformLocation("colour3");

    GLuint rectt[] = {0, 1, 2, 1, 2, 3};
    GLfloat backgroundv[] = {-1.0f, 1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f};
    GLfloat slidespacev[] = {-5.8f / 6.0f, -0.25f / 0.95f, 5.8f / 6.0f, -0.25f / 0.95f, -5.8f / 6.0f, -0.75f / 0.95f, 5.8f / 6.0f, -0.75f / 0.95f};
    GLfloat spectrumv[] = {-5.8f / 6.0f, 0.75f / 0.95f, 5.8f / 6.0f, 0.75f / 0.95f, -5.8f / 6.0f, -0.25f / 0.95f, 5.8f / 6.0f, -0.25f / 0.95f};
    GLuint slidert[] = {0, 1, 2};
    GLfloat sliderv[] = {0.0f, -0.25f / 0.95f, -0.2f / 6.0f, -0.75f / 0.95f, 0.2f / 6.0f, -0.75f / 0.95f};

    glGenVertexArrays(1, &backgroundvao);
    glBindVertexArray(backgroundvao);
    glGenBuffers(1, &backgroundvbo);
    glBindBuffer(GL_ARRAY_BUFFER, backgroundvbo);
    glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(GLfloat), backgroundv, GL_DYNAMIC_DRAW);
    glGenBuffers(1, &backgroundebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, backgroundebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(GLuint), rectt, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
    glEnableVertexAttribArray(0);

    glGenVertexArrays(1, &slidespacevao);
    glBindVertexArray(slidespacevao);
    glGenBuffers(1, &slidespacevbo);
    glBindBuffer(GL_ARRAY_BUFFER, slidespacevbo);
    glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(GLfloat), slidespacev, GL_DYNAMIC_DRAW);
    glGenBuffers(1, &slidespaceebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, slidespaceebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(GLuint), rectt, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
    glEnableVertexAttribArray(0);

    glGenVertexArrays(1, &spectrumvao);
    glBindVertexArray(spectrumvao);
    glGenBuffers(1, &spectrumvbo);
    glBindBuffer(GL_ARRAY_BUFFER, spectrumvbo);
    glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(GLfloat), spectrumv, GL_DYNAMIC_DRAW);
    glGenBuffers(1, &spectrumebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, spectrumebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(GLuint), rectt, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
    glEnableVertexAttribArray(0);

    glGenVertexArrays(1, &slidervao);
    glBindVertexArray(slidervao);
    glGenBuffers(1, &slidervbo);
    glBindBuffer(GL_ARRAY_BUFFER, slidervbo);
    glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(GLfloat), sliderv, GL_DYNAMIC_DRAW);
    glGenBuffers(1, &sliderebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sliderebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(GLuint), slidert, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
    glEnableVertexAttribArray(0);
}

void SGHueSelectRenderer::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    (*shaderprogramme).bind();
    glUniform1f(gvppointerposition, SGSelectPageManagement::selectedhue);
    glUniform1ui(gvpcolour2, SGGeneralLibrary::maxsaturatedcolour(SGSelectPageManagement::selectedhue));
    glUniform1ui(gvpcolour3, SGGeneralLibrary::ColourCSSToUint(SGCentralManagement::colour3));
    glUniform1i(gvprendertype, 1);
    glBindVertexArray(backgroundvao);
    glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_INT, (void*)(0 * sizeof(GLuint)));
    glUniform1i(gvprendertype, 2);
    glBindVertexArray(slidespacevao);
    glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_INT, (void*)(0 * sizeof(GLuint)));
    glUniform1i(gvprendertype, 4);
    glBindVertexArray(spectrumvao);
    glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_INT, (void*)(0 * sizeof(GLuint)));
    glUniform1i(gvprendertype, 3);
    glBindVertexArray(slidervao);
    glDrawElements(GL_TRIANGLES, 1 * 3, GL_UNSIGNED_INT, (void*)(0 * sizeof(GLuint)));
}

void SGHueSelectRenderer::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
}

void SGHueSelectRenderer::ResizeObj(){
    (*this).resize(QSize(12.0f * SGCentralManagement::sizeunit, 1.9f * SGCentralManagement::sizeunit));
}

bool SGHueSelectRenderer::event(QEvent *event){
    if((*event).type() == QEvent::TouchBegin || (*event).type() == QEvent::TouchUpdate){
        QTouchEvent* te = (QTouchEvent*)(event);
        float x = (*te).points()[0].position().x();
        if(x < 0.0){x = 0.0f;}
        else if(x > (*this).size().width()){x = (*this).size().width();}
        x /= (*this).size().width();
        SGSelectPageManagement::selectedhue = x;
        (*this).update();
        return true;
    }
    else if((*event).type() == QEvent::MouseButtonPress || (*event).type() == QEvent::MouseMove){return false;}
    return QWidget::event(event);
}
