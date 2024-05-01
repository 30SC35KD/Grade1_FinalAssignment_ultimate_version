#ifndef SELECTDIALOG2_H
#define SELECTDIALOG2_H

#include<QPaintEvent>
#include <QWidget>
#include"playerbutton.h"
class selectdialog2 : public QWidget
{
    Q_OBJECT
public:
    explicit selectdialog2(QWidget *parent = nullptr);
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

};

#endif // SELECTDIALOG2_H
