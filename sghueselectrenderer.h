#ifndef SGHUESELECTRENDERER_H
#define SGHUESELECTRENDERER_H

#include <QWidget>
#include "openglincludes.h"

class SGHueSelectRenderer : public QOpenGLWidget, public QOpenGLFunctions_4_5_Core
{
    Q_OBJECT
public:
    SGHueSelectRenderer(QWidget* parent);
    ~SGHueSelectRenderer();
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    QOpenGLShaderProgram* shaderprogramme;
    QOpenGLShader* vertexshader;
    QOpenGLShader* fragmentshader;
    GLuint gvppointerposition;
    GLuint gvprendertype;
    GLuint gvpcolour2;
    GLuint gvpcolour3;
    GLuint backgroundvao;
    GLuint backgroundvbo;
    GLuint backgroundebo;
    GLuint slidespacevao;
    GLuint slidespacevbo;
    GLuint slidespaceebo;
    GLuint slidervao;
    GLuint slidervbo;
    GLuint sliderebo;
    GLuint spectrumvao;
    GLuint spectrumvbo;
    GLuint spectrumebo;
    bool event(QEvent *event) override;
public slots:
    void ResizeObj();
};

#endif // SGHUESELECTRENDERER_H
