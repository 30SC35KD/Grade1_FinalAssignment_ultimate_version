#ifndef SELECTBUTTON1_H
#define SELECTBUTTON1_H

#include<QPushButton>

class selectbutton1:public QPushButton
{

public:
    selectbutton1(QString beforeImg,QString afterImg="");
    QString beforeImgPath;
    QString afterImgPath;
    void zoomdown();
    void zoomup();

};

#endif // SELECTBUTTON1_H
