#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customtime.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void update_and_display();

    void on_pause_button_clicked();

    void on_start_button_clicked();

private:
    Ui::MainWindow *ui;
    CustomTime* time;
    bool dontRunAgain;
    bool paused;
//    Timer timer;
};

#endif // MAINWINDOW_H
