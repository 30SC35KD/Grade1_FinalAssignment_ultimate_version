#ifndef PLAYER_H
#define PLAYER_H

#include<QLabel>
#include <QObject>
#include <QWidget>
#include<QPixmap>
#include<QTimer>
class player : public QLabel
{
    Q_OBJECT
public:
    player();
    qreal v=0;
    qreal height;
    qreal weight;
    void jump1();
    void jump2();
    bool up=false;
    QTimer jumptime1;
    QTimer jumptime2;
    qreal gravity=0;
    qreal jumpspeed=0;
    qreal v_jump;
    qreal v_run=0;
    qreal left;
    qreal right;
    qreal top;
    qreal bottom;
    int getY();
    QString name;
    qreal temp;
    QString scores[30];
    int num=0;
signals:
};
#endif // PLAYER_H
