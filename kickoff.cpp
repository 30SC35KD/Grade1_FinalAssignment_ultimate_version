#include "kickoff.h"
#include<QPushButton>
#include<QPropertyAnimation>
kickoff::kickoff(QString beforeImg,QString afterImg)
{
    this->beforeImgPath=beforeImg;
    this->afterImgPath=afterImg;
    QPixmap pix;
    pix.load(beforeImg);
    this->setFixedSize(150,150);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(150,150));

}
void kickoff::zoomdown()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(50);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}
void kickoff::zoomup()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(50);
    animation->setStartValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}


