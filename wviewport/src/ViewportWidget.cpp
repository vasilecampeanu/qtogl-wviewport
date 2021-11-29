#include <wviewport/ViewportWidget.h>

ViewportWidget::ViewportWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
}

ViewportWidget::~ViewportWidget()
{
}

void ViewportWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1);
}

void ViewportWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ViewportWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}