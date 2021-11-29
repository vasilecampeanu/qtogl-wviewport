#if !defined(VIEWPORTWIDGET_H_INCLUDED)
#define VIEWPORTWIDGET_H_INCLUDED

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>

class ViewportWidget 
    : public QOpenGLWidget
    , protected QOpenGLFunctions 
{
    Q_OBJECT
public:
    explicit ViewportWidget(QWidget* parent = nullptr);
    ~ViewportWidget();

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;

private: 
};

#endif // VIEWPORTWIDGET_H_INCLUDED
