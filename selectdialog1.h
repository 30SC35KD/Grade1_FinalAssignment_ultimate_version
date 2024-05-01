#ifndef SELECTDIALOG1_H
#define SELECTDIALOG1_H

#include<QPaintEvent>
#include <QWidget>
#include"playerbutton.h"
#include<QObject>
class selectdialog1 : public QWidget
{
    Q_OBJECT
public:
    explicit selectdialog1(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    playerbutton *messi;
    playerbutton *ronaldo;
    playerbutton *neymar;
    playerbutton *mbappe;
    playerbutton *modric;
    playerbutton *virgil;
    playerbutton *lukaku;
    playerbutton *bale;
    playerbutton *muller;
    playerbutton *son;
signals:
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
};

#endif // SELECTDIALOG1_H
