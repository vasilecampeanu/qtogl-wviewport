#include <wviewport/MainWindow.h>
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    MainWindow window;

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    
    for (const QString &locale : uiLanguages) {
        const QString baseName = "wviewport_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            application.installTranslator(&translator);
            break;
        }
    }
    
    window.show();

    return application.exec();
}
