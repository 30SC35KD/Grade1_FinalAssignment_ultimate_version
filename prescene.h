#ifndef PRESCENE_H
#define PRESCENE_H

#include"selectbutton1.h"
#include <QMainWindow>
#include<QPaintEvent>
#include"kickoff.h"
#include"game.h"
#include<QObject>
#include"selectdialog1.h"
#include"selectdialog2.h"
class prescene : public QMainWindow
{
    Q_OBJECT
public:
    explicit prescene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    selectbutton1*selectbutton0;
    selectbutton1*selectbutton;
    kickoff*kick_off;
    game*g;
    bool choose_p1=false;
    bool choose_p2=false;
    selectdialog1 *select1=NULL;
    selectdialog2 *select2=NULL;
signals:
void playmusic();
public slots:

};
#endif // PRESCENE_H
