#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Server.h"
#include <QMainWindow>

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
    void on_u_planButton_clicked();

    void on_u_startButton_clicked();

    void on_u_stopButton_clicked();

    void on_u_pauseButton_clicked();

    void on_u_resumeButton_clicked();

    int randomNum();
    void numerousTest(int times);

private:
    Ui::MainWindow *ui;
    Server server;
};

#endif // MAINWINDOW_H
