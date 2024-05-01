#ifndef KICKOFF_H
#define KICKOFF_H

#include<QPushButton>
class kickoff:public QPushButton
{
public:
    kickoff(QString beforeImg,QString afterImg="");
    QString beforeImgPath;
    QString afterImgPath;
    void zoomdown();
    void zoomup();
};
#endif // KICKOFF_H
