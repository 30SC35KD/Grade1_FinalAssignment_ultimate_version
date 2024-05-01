#include "win1.h"
#include<QPainter>
#include<QLabel>
#include<QPalette>
#include<QPushButton>
#include<QApplication>
#include<QProcess>
#include<QDir>
#include<QDebug>
#include<QRandomGenerator>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia/QAudioOutput>
win1::win1(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(800,500);
    this->setWindowTitle("SoccerGoal");
    setWindowIcon(QIcon(":/new/prefix1/image/soccerfourth.jpg"));
    QLabel *q=new QLabel(this);
    q->setFixedSize(800,500);
    q->move(100,-10);
    q->setText("Congratulations on P1's Victory!");
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);
    q->setPalette(pe);
    q->setFont(QFont("Roman typeface",33,87));
    QPushButton *returnback=new QPushButton(this);
    returnback->setFont(QFont("Roman typeface",18));
    returnback->setText("Return");
    returnback->setGeometry(650,400,100,50);
    connect(returnback,&QPushButton::clicked,[=]{    qApp->closeAllWindows();
    QProcess::startDetached(QApplication::applicationFilePath(), QApplication::arguments(), QDir::currentPath());
   });//重新开始

//随机播放解说
QAudioOutput *audioOutput=new  QAudioOutput(this);
QMediaPlayer *hewei=new QMediaPlayer(this);  //创建一个音乐播放
hewei->setAudioOutput(audioOutput );
audioOutput->setVolume(1.5);
int m=QRandomGenerator::global()->bounded(12);
qDebug()<<m;
switch(m)
{
case 0:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h1.mp3"));
hewei->play();
break;
case 1:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h2.mp3"));
hewei->play();
break;
case 2:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h3.mp3"));
hewei->play();
break;
case 3:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h4.mp3"));
hewei->play();
break;
case 4:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h5.mp3"));
hewei->play();
break;
case 5:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h6.mp3"));
hewei->play();
break;
case 6:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h7.mp3"));
hewei->play();
break;
case 7:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h8.mp3"));
hewei->play();
break;
case 8:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h9.mp3"));
hewei->play();
break;
case 9:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h10.mp3"));
hewei->play();
break;
case 10:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h11.mp3"));
hewei->play();
break;
case 11:
hewei->setSource(QUrl("qrc:/new/prefix1/sound/h12.mp3"));
hewei->play();
break;
}
}

void win1::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    QPixmap winground;
    winground.load(":/new/prefix1/image/win.jpg");
    p.drawPixmap(0,0,this->width(),this->height(),winground);
}
