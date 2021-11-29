#if !defined(MAINWINDOW_H_INCLUDED)
#define MAINWINDOW_H_INCLUDED

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H_INCLUDED
