#include "selectbutton1.h"
#include<QPropertyAnimation>

selectbutton1:: selectbutton1(QString beforeImg,QString afterImg)
{
    this->beforeImgPath=beforeImg;
    this->afterImgPath=afterImg;
    QPixmap pix;
    pix.load(beforeImg);
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

}
void selectbutton1::zoomdown()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(50);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}
void selectbutton1::zoomup()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(50);
    animation->setStartValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}
