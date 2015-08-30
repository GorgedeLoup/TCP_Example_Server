#include "variable.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTest>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHash<float, QList<Spot3DCoordinate> > spot;

    Spot3DCoordinate spot1, spot2, spot3, spot4, spot5;
    spot1.x = 11; spot1.y = 12; spot1.z = 13;
    spot2.x = 21; spot2.y = 22; spot2.z = 23;
    spot3.x = 31; spot3.y = 32; spot3.z = 33;
    spot4.x = 41; spot4.y = 42; spot4.z = 43;
    spot5.x = 51; spot5.y = 52; spot5.z = 53;
    QList<Spot3DCoordinate> spotList45;
    spotList45 << spot1 << spot2 << spot3 << spot4 << spot5;
    spot[45.0] = spotList45;

    Spot3DCoordinate spot6, spot7, spot8, spot9;
    spot6.x = 1.1; spot6.y = 1.2; spot6.z = 1.3;
    spot7.x = 2.1; spot7.y = 2.2; spot7.z = 2.3;
    spot8.x = 3.1; spot8.y = 3.2; spot8.z = 3.3;
    spot9.x = 4.1; spot9.y = 4.2; spot9.z = 4.3;
    QList<Spot3DCoordinate> spotList90;
    spotList90 << spot6 << spot7 << spot8 << spot9;
    spot[90.0] = spotList90;


    QHash<float, QList<int> > spotOrder;

    QList<int>  spotOrderList1, spotOrderList2;
    spotOrderList1 << 1 << 2 << 3 << 4 << 5;
    spotOrderList2 << 10 << 9 << 8 << 7 << 6;
    spotOrder[45.0] = spotOrderList1;
    spotOrder[90.0] = spotOrderList2;


    SpotSonicationParameter parameter;
    parameter.volt = 5;
    parameter.totalTime = 10;
    parameter.period = 500;
    parameter.dutyCycle = 50;
    parameter.coolingTime = 5;

    server.setCoordinate(spot);
    server.setSpotOrder(spotOrder);
    server.setParameter(parameter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_u_planButton_clicked()
{  
    //server.sendPlanHash();
    numerousTest(100);
}

void MainWindow::on_u_startButton_clicked()
{
    server.sendCommandStart();
}

void MainWindow::on_u_stopButton_clicked()
{
    server.sendCommandStop();
}

void MainWindow::on_u_pauseButton_clicked()
{
    server.sendCommandPause();
}

void MainWindow::on_u_resumeButton_clicked()
{

    server.sendCommandResume();
}


int MainWindow::randomNum()
{
    QTime time;
    time = QTime::currentTime();
    qsrand(time.msec() + time.second()*1000);

    int randNum = qrand() % 4;
    return randNum;
}


void MainWindow::numerousTest(int times)
{
    for (int i = 0; i < times; i++)
    {
        int randNum = randomNum();
        switch (randNum) {
        case 0:
            server.sendPlanHash();
            QTest::qWait(500);
            break;
        case 1:
            server.sendCommandStart();
            QTest::qWait(500);
            break;
        case 2:
            server.sendCommandStop();
            QTest::qWait(500);
            break;
        case 3:
            server.sendCommandPause();
            QTest::qWait(500);
            break;
        case 4:
            server.sendCommandResume();
            QTest::qWait(500);
            break;
        default:
            break;
        }
    }
}
