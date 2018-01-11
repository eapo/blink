#include "blinkwindow.h"

#include <QApplication>
#include <QDesktopWidget>

BlinkWindow::BlinkWindow(QWidget *parent) :
    QMainWindow(parent),
    blinking(false),
    counter(0)
{
    setWindowFlags(windowFlags() |
                   Qt::X11BypassWindowManagerHint |
                   Qt::CustomizeWindowHint |
                   Qt::FramelessWindowHint |
                   Qt::WindowStaysOnTopHint |
                   Qt::WindowTransparentForInput |
                   Qt::WindowDoesNotAcceptFocus);

    //set geometry to cover all available screens
    QRect geometry;
    int screen_amount = QApplication::desktop()->numScreens();
    for(int i=0; i<screen_amount; ++i)
    {
        QRect screen(QApplication::desktop()->screenGeometry(i));
        if(screen.top() < geometry.top())
            geometry.setTop(screen.top());
        if(screen.bottom() > geometry.bottom())
            geometry.setBottom(screen.bottom());
        if(screen.left() < geometry.left())
            geometry.setLeft(screen.left());
        if(screen.right() > geometry.right())
            geometry.setRight(screen.right());
    }
    setGeometry(geometry);

    setStyleSheet("background-color: white;");

    //initialize the timer
    blinker.connect(&blinker, &QTimer::timeout, this, &BlinkWindow::blink);
    blinker.start(0);
}

BlinkWindow::~BlinkWindow()
{
}

void BlinkWindow::blink()
{
    if((blinking = !blinking))
    {
        //blink
        ++counter;
        setWindowOpacity(1);
        blinker.start(100);
    }
    else
    {
        //unblink
        setWindowOpacity(0);
        blinker.start(6000);

    }

}









