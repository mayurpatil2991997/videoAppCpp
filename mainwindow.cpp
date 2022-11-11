#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include <QQmlContext>
#include <QQmlEngine>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QQmlEngine engine;
//    QQmlComponent component(&engine,QUrl::fromLocalFile("qml:/videoUi.qml"));
//    QObject *object = component.create();

//    QQuickWidget *view = new QQuickWidget;
//    view->rootContext()->setContextProperty("mainwindow",this);
//    view->setSource(QUrl(QStringLiteral("qrc:/videoUi.qml")));

//    view = new QQuickWidget;
//    view->setSource(QUrl::fromLocalFile("qrc:/videoUi.qml"));
//    view->show();


    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);

    slider = new QSlider(this);
    bar = new QProgressBar(this);

    slider->setOrientation(Qt::Horizontal);

    ui->statusbar->addPermanentWidget(slider);
    ui->statusbar->addPermanentWidget(bar);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    qDebug() << "Called";
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.mpg)");
    on_actionStop_triggered();

    player->setMedia(QUrl::fromLocalFile(filename));

    on_actionPlay_triggered();
}

void MainWindow::on_actionPlay_triggered()
{
    player->play();
    ui->statusbar->showMessage("Playing");
}

void MainWindow::on_actionPause_triggered()
{
    player->pause();
    ui->statusbar->showMessage("Paused...");
}

void MainWindow::on_actionStop_triggered()
{
    player->stop();
    ui->statusbar->showMessage("Stopped");
}
