#include "sgcomplementarycolourrenderer.h"
#include "sgcentralmanagement.h"
#include "sggenerallibrary.h"
#include "sgillusionmanagement.h"
#include "sgselectpagemanagement.h"

SGComplementaryColourRenderer::SGComplementaryColourRenderer(QWidget *parent){
    (*this).setParent(parent);
    (*this).show();
    (*this).ResizeObj();
}

SGComplementaryColourRenderer::~SGComplementaryColourRenderer(){
    makeCurrent();
    doneCurrent();
}

void SGComplementaryColourRenderer::initializeGL(){
    initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    vertexshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    (*vertexshader).compileSourceFile(":/assets/complementarycolour.vert");
    fragmentshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    (*fragmentshader).compileSourceFile(":/assets/complementarycolour.frag");
    shaderprogramme = new QOpenGLShaderProgram(this);
    (*shaderprogramme).addShader(vertexshader);
    (*shaderprogramme).addShader(fragmentshader);
    (*shaderprogramme).link();
    gvpdisplaycolour = (*shaderprogramme).uniformLocation("displaycolour");
    gvpwindowsize = (*shaderprogramme).uniformLocation("windowsize");
    gvpblankcolour = (*shaderprogramme).uniformLocation("blankcolour");
    
    GLfloat v[] = {-1.0f, 1.0f, 1.0f, 1.0f, -1.0f, -1.0f, 1.0f, -1.0f};
    GLuint t[] = {0, 1, 2, 1, 2, 3};
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(GLfloat), v, GL_DYNAMIC_DRAW);
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * 3 * sizeof(GLuint), t, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)(0 * sizeof(GLfloat)));
    glEnableVertexAttribArray(0);
}

void SGComplementaryColourRenderer::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    (*shaderprogramme).bind();
    glUniform2f(gvpwindowsize, (*this).size().width(), (*this).size().height());
    glUniform1ui(gvpdisplaycolour, SGGeneralLibrary::maxsaturatedcolour(SGSelectPageManagement::selectedhue + 0.5f));
    glUniform1ui(gvpblankcolour, SGGeneralLibrary::ColourCSSToUint(SGCentralManagement::colour2));
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_INT, (void*)(0 * sizeof(GLuint)));
}

void SGComplementaryColourRenderer::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
}

void SGComplementaryColourRenderer::ResizeObj(){
    (*this).move(QPoint(0.0f, SGCentralManagement::sizeunit));
    (*this).resize(QSize((*parentWidget()).size().width(), (*parentWidget()).size().height() - SGCentralManagement::sizeunit));
}
