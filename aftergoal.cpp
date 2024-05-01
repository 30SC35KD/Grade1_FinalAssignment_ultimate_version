#include "aftergoal.h"
#include<QPainter>
#include<QPushButton>
#include<QLabel>
#include<QMovie>
#include<QString>
aftergoal::aftergoal(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(750,450);
    setWindowIcon(QIcon(":/new/prefix1/image/soccer_aftergoal.jpg"));
    celebrate->move(100,300);
    celebrate->setFixedSize(150,50);
    celebrate->setFont(QFont("Roman typeface",18));
    celebrate->setText("Celebrate");//庆祝按键
    continue0->move(500,300);
    continue0->setFixedSize(150,50);
    continue0->setFont(QFont("Roman typeface",18));
    continue0->setText("Continue");//继续按键
    connect(continue0,&QPushButton::released,[=]{
        this->hide();
        this->P1_IsGoal=false;
        this->P2_IsGoal=false;
        emit recover();
    });//恢复运动
    connect(celebrate,&QPushButton::clicked,[=]
            {
                if(this->t=="messi")
                    this->playgif(":/new/prefix1/image/messi.gif");
                if(this->t=="ronaldo")
                    this->playgif(":/new/prefix1/image/ronaldo.gif");
                if(this->t=="neymar")
                    this->playgif(":/new/prefix1/image/neymar.gif");
                if(this->t=="modric")
                    this->playgif(":/new/prefix1/image/modric.gif");
                if(this->t=="mbappe")
                    this->playgif(":/new/prefix1/image/mbappe.gif");
                if(this->t=="virgil")
                    this->playgif(":/new/prefix1/image/virgil.gif");
                if(this->t=="lukaku")
                    this->playgif(":/new/prefix1/image/lukaku.gif");
                if(this->t=="muller")
                    this->playgif(":/new/prefix1/image/muller.gif");
                if(this->t=="bale")
                    this->playgif(":/new/prefix1/image/bale.gif");
                if(this->t=="son")
                    this->playgif(":/new/prefix1/image/son.gif");
            });
}//庆祝动画

void aftergoal::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap prebackground;
    prebackground.load(":/new/prefix1/image/goal.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),prebackground);
}

void aftergoal::playgif(QString path)
{QLabel *label = new QLabel(this);
    QMovie *movie = new QMovie(path);
    label->setMovie(movie); // 1. 设置要显示的 GIF 动画图片
    movie->start();         // 2. 启动动画
    label->show();
    label->move(375-0.5*label->width(),300-0.5*height());
    QObject::connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        // GIF 动画执行一次就结束
        if (frameNumber == movie->frameCount() - 1) {
            movie->stop();
        }
    });
}
