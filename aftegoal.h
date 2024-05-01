#ifndef AFTEGOAL_H
#define AFTEGOAL_H

#include<QPushButton>
#include <QWidget>

class aftergoal : public QWidget
{
    Q_OBJECT
public:
    explicit aftergoal(QWidget *parent = nullptr);
    bool P1_IsGoal=false;
    bool P2_IsGoal=false;
    QPushButton *celebrate=new QPushButton(this);
    QPushButton *continue0=new QPushButton(this);
    void playgif(QString path);
    void paintEvent(QPaintEvent*);
    QString t=NULL;
signals:
    void recover();
};

#endif // AFTEGOAL_H
