#ifndef WIN2_H
#define WIN2_H

#include <QWidget>

class win2 : public QWidget
{
    Q_OBJECT
public:
    explicit win2(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    struct timeval
    {
        long tv_sec;
        long tv_usec;
    };


public slots:

signals:
};

#endif // WIN2_H
