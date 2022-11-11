#include "mainwindow.h"

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow testClass;
    qmlRegisterType<MainWindow>("com.company.mainwindow",1,0,"Mainwindow");
      QQmlApplicationEngine engine;
      engine.load(QUrl(QStringLiteral("videoUi.qml")));

    MainWindow w;
    w.show();

//    QQmlContext * rootContext = engine.rootContext();
//    rootContext->setContextProperty("classA",&testClass);
    return a.exec();
}
