#ifndef SGCOMPLEMENTARYCOLOURRENDERER_H
#define SGCOMPLEMENTARYCOLOURRENDERER_H

#include <QWidget>
#include "openglincludes.h"

class SGComplementaryColourRenderer : public QOpenGLWidget, public QOpenGLFunctions_4_5_Core
{
    Q_OBJECT
public:
    SGComplementaryColourRenderer(QWidget* parent);
    ~SGComplementaryColourRenderer();
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    QOpenGLShaderProgram* shaderprogramme;
    QOpenGLShader* vertexshader;
    QOpenGLShader* fragmentshader;
    GLuint gvpwindowsize;
    GLuint gvpdisplaycolour;
    GLuint gvpblankcolour;
    GLuint vao;
    GLuint vbo;
    GLuint ebo;
public slots:
    void ResizeObj();
};

#endif // SGCOMPLEMENTARYCOLOURRENDERER_H
