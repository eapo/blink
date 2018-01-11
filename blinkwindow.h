#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

class BlinkWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BlinkWindow(QWidget *parent = 0);
    ~BlinkWindow();

public slots:
    void blink();

private:
    QTimer blinker;
    bool blinking;

    int counter;

};

#endif // MAINWINDOW_H
