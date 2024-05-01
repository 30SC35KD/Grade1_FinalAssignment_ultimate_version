#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QPainter>
#include "button.h"
#include<QTimer>
#include<QtMultimedia/QMediaPlayer>
#include<QPushButton>
#include<QtMultimedia/QSoundEffect>
#include<QtMultimedia/QMediaCaptureSession>
#include<QUrl>
#include<QAudioOutput>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1000,600);
    setWindowTitle("SoccerGoal");
    setWindowIcon(QIcon(":/new/prefix1/image/soccer (1).jpg"));
    Button*startbutton=new Button(":/new/prefix1/image/play.png");
    startbutton->setParent(this);
    startbutton->move(this->width()*0.5-startbutton->width()*0.5,this->height()*0.45);
    QAudioOutput *audioOutput=new  QAudioOutput(this);
    QMediaPlayer *startSound=new QMediaPlayer(this);  //创建一个音乐播放
    startSound->setAudioOutput(audioOutput );
    audioOutput->setVolume(0.2);
    startSound->setSource(QUrl("qrc:/new/prefix1/sound/brazilworldcup.mp3"));
startSound->play();
    startSound->setLoops(30);
QPushButton *b=new QPushButton(this);//创建帮助键
    QIcon icon;
    icon.addFile(tr(":/new/prefix1/image/help.png"));
    b->setIcon(icon);
    b->move(900,0);
    b->setFixedSize(100,50);
    b->setIconSize(b->size());
    QWidget *w=new QWidget;
    QLabel *l=new QLabel(w);
    QPixmap *pixmap = new QPixmap(":/new/prefix1/image/helpword.png");
    pixmap->scaled(l->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    l->setScaledContents(true);
    l->setPixmap(*pixmap);
    w->setFixedSize(400,400);
    connect(b,&QPushButton::clicked,[=]{

        w->show();
    });
    Preparation=new prescene;//显示下一个界面
    connect(startbutton,&Button::clicked,[=](){
        startbutton->zoomdown();
        startbutton->zoomup();

        QTimer::singleShot(350,this,[=]()
                           {
                               this->hide();
                            startSound->stop();
                               Preparation->show();
                            startSound->setSource(QUrl("qrc:/new/prefix1/sound/europechamp.mp3"));
                            startSound->play();
                            startSound->setLoops(30);
        });

    });
    connect(Preparation,&prescene::playmusic,[=]{startSound->stop();});
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap openbackground;
    openbackground.load(":/new/prefix1/image/openbackground.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),openbackground);
    QPixmap title;
    title.load(":/new/prefix1/image/title.png");
    painter.drawPixmap(100,125,800,100,title);
}
MainWindow::~MainWindow()
{
    delete ui;
}
