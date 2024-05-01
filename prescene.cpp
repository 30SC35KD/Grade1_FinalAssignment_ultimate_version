#include "prescene.h"
#include<QPainter>
#include<QPixmap>
#include<QPaintEvent>
#include"selectbutton1.h"
#include<QString>
#include<QTimer>
#include<QObject>
#include"selectdialog1.h"
#include"selectdialog2.h"
#include"kickoff.h"
#include"game.h"
#include<QtMultimedia/QtMultimedia>

prescene::prescene(QWidget*parent): QMainWindow{parent}
{
    this->setFixedSize(1000,600);
    this->setWindowTitle("SoccerGoal");
    this->setWindowIcon(QIcon(":/new/prefix1/image/soccer.jpg"));
    selectbutton=new selectbutton1(":/new/prefix1/image/choose.png");
    selectbutton->setParent(this);
    selectbutton->move(this->width()*0.2-selectbutton->width()*0.5,this->height()*0.05);
    selectbutton0=new selectbutton1(":/new/prefix1/image/choose2.png");
    selectbutton0->setParent(this);
    selectbutton0->move(this->width()*0.8-selectbutton->width()*0.5,this->height()*0.05);
    kick_off=new kickoff(":/new/prefix1/image/kickoff.png");
    kick_off->setParent(this);
    kick_off->move(this->width()*0.42,this->height()*0.65);
    kick_off->setDisabled(true);
    select1=new selectdialog1;
    connect(selectbutton,&QPushButton::clicked,[=]{

        this->choose_p1=true;
        if(this->choose_p1==true&&this->choose_p2==true)
        {
            kick_off->setDisabled(false);
            this->choose_p2=false;
            this->choose_p1=false;
        }
        selectbutton->zoomdown();
        selectbutton->zoomup();
        QTimer::singleShot(200,this,[=]()
                           {
                               select1->show();
                               selectbutton->setDisabled(true);
                           });


    });
    select2=new selectdialog2;
    connect(selectbutton0,&QPushButton::clicked,[=]{
        this->choose_p2=true;

        if(this->choose_p1==true&&this->choose_p2==true)
        {
            kick_off->setDisabled(false);
            this->choose_p2=false;
            this->choose_p1=false;
        }
        selectbutton0->zoomdown();
        selectbutton0->zoomup();
        QTimer::singleShot(200,this,[=]()
                           {
                               select2->show();
                               selectbutton0->setDisabled(true);
                           });
    });
    g=new game;
    //创建球员信号的接收
    connect(select1,SIGNAL(create_messi1()),g,SLOT(create_messi1()));
    connect(select1,SIGNAL(create_ronaldo1()),g,SLOT(create_ronaldo1()));
    connect(select1,SIGNAL(create_neymar1()),g,SLOT(create_neymar1()));
    connect(select1,SIGNAL(create_modric1()),g,SLOT(create_modric1()));
    connect(select1,SIGNAL(create_mbappe1()),g,SLOT(create_mbappe1()));
    connect(select1,SIGNAL(create_virgil1()),g,SLOT(create_virgil1()));
    connect(select1,SIGNAL(create_lukaku1()),g,SLOT(create_lukaku1()));
    connect(select1,SIGNAL(create_muller1()),g,SLOT(create_muller1()));
    connect(select1,SIGNAL(create_bale1()),g,SLOT(create_bale1()));
    connect(select1,SIGNAL(create_son1()),g,SLOT(create_son1()));
    connect(select2,SIGNAL(create_messi2()),g,SLOT(create_messi2()));
    connect(select2,SIGNAL(create_ronaldo2()),g,SLOT(create_ronaldo2()));
    connect(select2,SIGNAL(create_neymar2()),g,SLOT(create_neymar2()));
    connect(select2,SIGNAL(create_modric2()),g,SLOT(create_modric2()));
    connect(select2,SIGNAL(create_mbappe2()),g,SLOT(create_mbappe2()));
    connect(select2,SIGNAL(create_virgil2()),g,SLOT(create_virgil2()));
    connect(select2,SIGNAL(create_lukaku2()),g,SLOT(create_lukaku2()));
    connect(select2,SIGNAL(create_muller2()),g,SLOT(create_muller2()));
    connect(select2,SIGNAL(create_bale2()),g,SLOT(create_bale2()));
    connect(select2,SIGNAL(create_son2()),g,SLOT(create_son2()));
    connect(kick_off,&QPushButton::clicked,[=]{
        kick_off->zoomdown();
        kick_off->zoomup() ;
        QTimer::singleShot(200,this,[=]()
                           {
                               this->hide();
            emit playmusic();
                               g->show();
            QAudioOutput *audioOutput=new  QAudioOutput(g);
                               QMediaPlayer *gameSound=new QMediaPlayer(g);  //创建一个音乐播放
                               gameSound->setAudioOutput(audioOutput );
                               audioOutput->setVolume(0.8);
                               gameSound->setSource(QUrl("qrc:/new/prefix1/sound/groundmusic.mp3"));
                               gameSound->play();
                               gameSound->setLoops(30);
                           });
    });

}

void prescene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap prebackground;
    prebackground.load(":/new/prefix1/image/prebackground.png");
    painter.drawPixmap(0,0,this->width(),this->height(),prebackground);
}

