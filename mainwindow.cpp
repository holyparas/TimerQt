#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QSound>
#include <QTimer>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dontRunAgain(false),
    paused(false)
{
    ui->setupUi(this);
    time = new CustomTime();
    ui->hour_label->setText(0);
    ui->minute_label->setText(0);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete time;
}



void MainWindow::on_start_button_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Time Input",
                                             "Time to be set:", QLineEdit::Password,
                                             "00:30", &ok);
    QStringList timeComponents;
    int hours,minutes;
    if (ok && !text.isEmpty()){
        timeComponents = text.split(":");
        hours = timeComponents.at(0).toInt();
        minutes = timeComponents.at(1).toInt();
    }
    qDebug() << hours << " " << minutes;
    time->setHours(hours);
    time->setMinutes(minutes);
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update_and_display()));
    timer->start(1000);
}

void MainWindow::update_and_display()
{
//    qDebug() << "minutes b4 update: " << time->getMinutes();

    if(dontRunAgain || paused)
        return;

    if(time->getHours() == 0 && time->getMinutes() == 0){
        ui->hour_label->setStyleSheet("QLabel {color : red; }");
        ui->minute_label->setStyleSheet("QLabel {color : red; }");
        ui->hour_label->setText(0);
        ui->minute_label->setText(0);
        QSound::play(":GameOver.wav");
        dontRunAgain = true;


    }else if(time->getMinutes() == 0 && time->getHours() != 0){
        int hours = time->getHours();
        hours--;
        time->setHours(hours);
        time->setMinutes(60);
    }
    if(time->getSeconds() == 60){
        int minutes = time->getMinutes();
//        qDebug() << "minutes b4 update: " << time->getMinutes();
        minutes--;
        time->setMinutes(minutes);
//        qDebug() << "mins after update: " << time->getMinutes();
        time->setSeconds(0);
    }
    int seconds = time->getSeconds();
    seconds++;
    time->setSeconds(seconds);
    //these 2 below potentially not working because of sending an int to a string
    QString strHours = QString::number(time->getHours());
    QString strMinutes = QString::number(time->getMinutes());

    ui->hour_label->setText(strHours);
    ui->minute_label->setText(strMinutes);


}


void MainWindow::on_pause_button_clicked()
{
    if(paused == false){
        paused = true;
        QPalette pal = ui->pause_button->palette();
        pal.setColor(QPalette::Button, QColor(Qt::blue));
        ui->pause_button->setAutoFillBackground(true);
        ui->pause_button->setPalette(pal);
        ui->pause_button->update();
    }else{
        paused = false;
        ui->pause_button->setAutoFillBackground(false);
        ui->pause_button->update();
    }
}

