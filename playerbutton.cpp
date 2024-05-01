#include "playerbutton.h"
#include<QPropertyAnimation>

playerbutton::playerbutton(QString beforeImg,QString afterImg)
{
    this->beforeImgPath=beforeImg;
    this->afterImgPath=afterImg;
    QPixmap pix;
    pix.load(beforeImg);

    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(150,200));

}
void playerbutton::zoomdown()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(100);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}
void playerbutton::zoomup()
{
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(100);
    animation->setStartValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::Linear);
    animation->start();
}

