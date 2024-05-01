#ifndef BUTTON_H
#define BUTTON_H

#include <QMainWindow>
#include <QWidget>
#include<QPushButton>
class Button:public QPushButton
{
public:
    //点击按钮的显示
    Button(QString beforeImg,QString afterImg="");
    QString beforeImgPath;
    QString afterImgPath;
    void zoomdown();
    void zoomup();
};
#endif // BUTTON_H
