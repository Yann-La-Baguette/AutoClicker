#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
    ui->warningLabel->setVisible(false);
    QCoreApplication::setApplicationName("Auto Clicker");

    QHotkey *hotkey = new QHotkey(QKeySequence(Qt::Key_F6), true, this);

    connect(hotkey, &QHotkey::activated, this, &MainWindow::on_activateBtn_clicked);
}

MainWindow::~MainWindow(){
    delete ui;
    delete timer;
}

void MainWindow::on_clickSelector_activated(int index){
    click = index;
}

void MainWindow::on_timeSpinBox_valueChanged(int timeInSpinBox){
    time = timeInSpinBox;
    if(autoClickActivated){
        on_activateBtn_clicked();
    }
}

void MainWindow::on_activateBtn_clicked(){

    if(time != 0){
        ui->warningLabel->setVisible(false);
        if(autoClickActivated == false){
            autoClickActivated = true;
            ui->activateBtn->setText("Disactivate (F6)");
            ui->activateBtn->setStyleSheet("background-color: red;");
            timer->start(time);
        }
        else{
            autoClickActivated = false;
            ui->activateBtn->setText("Activate (F6)");
            ui->activateBtn->setStyleSheet("background-color: green;");
            timer->stop();
        }
    }
    else{
        ui->warningLabel->setText("Time value is wrong");
        ui->warningLabel->setVisible(true);
    }
}

void MainWindow::loop(){
    switch(click) {
    case 0:
        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        ui->warningLabel->setVisible(false);
        break;

    case 1:
        mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
        mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        ui->warningLabel->setVisible(false);
        break;

    default:
        if(click <= 27){
            Used_key = click + 63;

            keybd_event(Used_key,0,0,0);
            ui->warningLabel->setVisible(false);
        }
        else{
            ui->warningLabel->setText("Click value is wrong");
            ui->warningLabel->setVisible(true);
        }
        break;
    }
}
