#ifndef BALL_H
#define BALL_H

#include<QPainter>
#include<QPainterPath>
#include<QStyleOptionGraphicsItem>
#include <QObject>

class ball
{
public:
    ball();
    qreal x;
    qreal y;
    const qreal r=30;
    qreal vx;
    qreal vy;
    qreal g=0.1;
    qreal f=0.01;
    qreal left;
    qreal right;
    qreal bottom;
    qreal top;
};
#endif // BALL_H
