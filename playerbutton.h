#ifndef PLAYERBUTTON_H
#define PLAYERBUTTON_H

#include<QPushButton>

class playerbutton:public QPushButton
{

public:
    playerbutton(QString beforeImg,QString afterImg="");
    QString beforeImgPath;
    QString afterImgPath;
    void zoomdown();
    void zoomup();

};
#endif // PLAYERBUTTON_H
