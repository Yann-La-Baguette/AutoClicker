#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QTimer>
#include <windows.h>
#include <QHotkey/QHotkey>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_clickSelector_activated(int index);
    void on_timeSpinBox_valueChanged(int arg1);
    void on_activateBtn_clicked();
    void loop();


private:
    Ui::MainWindow *ui;
    QTimer *timer = new QTimer(this);
    bool autoClickActivated = false;
    int time = 1000;                                // Temps à 1 sec de base
    int click = 0;
    int Used_key;
};
#endif // MAINWINDOW_H
