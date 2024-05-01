#ifndef GAME_H
#define GAME_H

#include<QPaintEvent>
#include <QMainWindow>
#include"selectdialog1.h"
#include<QObject>
#include<QPixmap>
#include<QLabel>
#include<QKeyEvent>
#include<QTimer>
#include"player.h"
#include"playerbutton.h"
#include"ball.h"
#include"aftergoal.h"
#include<QLCDNumber>
#include"win1.h"
#include"win2.h"
class game : public QMainWindow
{
    Q_OBJECT
public:
    explicit game(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent* k);
    void keyReleaseEvent(QKeyEvent* k);
    player *p1=NULL;
    player *p2=NULL;
    QList<int> keys;
    QTimer* keyRespondTimer;
    void slotTimeOut();
    ball *b=new ball;
    void timerEvent(QTimerEvent *event);
    void header();
    void dribble();

    void Judge_Goal();
    QPushButton *button=new QPushButton(this);
    aftergoal *d=NULL;
    QLabel *p1_scores;
    QLabel *p2_scores;
    void scoreboard();
    QLCDNumber *lcdNumber=NULL;
    QTimer *count_time=NULL;
    win1 *w1=NULL;
    win2 *w2=NULL;
public slots:
    void create_messi1();
    void create_ronaldo1();
    void create_neymar1();
    void create_modric1();
    void create_mbappe1();
    void create_virgil1();
    void create_lukaku1();
    void create_muller1();
    void create_bale1();
    void create_son1();
    void create_messi2();
    void create_ronaldo2();
    void create_neymar2();
    void create_modric2();
    void create_mbappe2();
    void create_virgil2();
    void create_lukaku2();
    void create_muller2();
    void create_bale2();
    void create_son2();
    void recover();
    void startCountdown(); // 开始倒计时
    void startcountTimer(); // 启动计时器

signals:

};
#endif // GAME_H
