#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QTime>

const static QString SELECTED_COLOUR = "DDDDDD";
const static QString UNSELECTED_COLOUR = "C0BFBC";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnBottomHint);
    setParent(0); // Create TopLevel-Widget
    setAttribute(Qt::WA_NoSystemBackground, true);
    setAttribute(Qt::WA_TranslucentBackground, true);

    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
    timer->start(500);
    updateTime();

    resetClock();
    setTime(12,3);
}

void MainWindow::updateTime(){
    QTime currentTime = QTime::currentTime();
    int hours = currentTime.hour();
    int minutes = currentTime.minute();

    //24hr to 12hr
    if(hours==0&&hours!=12){
        hours=12;
     }
    else if(hours==12&&hours!=0){
        hours=12;
     }
    else if(hours<12&&hours!=0){
        hours=hours;
     }
    else if(hours>12&&hours!=0)
     {
        hours=hours-12;
     }

    resetClock();
    setTime(hours,minutes);
}

void MainWindow::resetClock(){
    const QString UNSELECTED_SS = "QLabel {color: rgba(200,200,200,70);}";
    const QString SELECTED_SS = "QLabel {color: #373737;}";
//    ui->FIVE_MIN->setStyleSheet(UNSELECTED_SS);
//    ui->TEN_MIN->setStyleSheet(UNSELECTED_SS);
//    ui->QUARTER->setStyleSheet(UNSELECTED_SS);
//    ui->TWENTY->setStyleSheet(UNSELECTED_SS);
//    ui->HALF->setStyleSheet(UNSELECTED_SS);
//    ui->PAST->setStyleSheet(UNSELECTED_SS);
//    ui->MINUTES->setStyleSheet(UNSELECTED_SS);
//    ui->TO->setStyleSheet(UNSELECTED_SS);

//    ui->ONE->setStyleSheet(UNSELECTED_SS);
//    ui->TWO->setStyleSheet(UNSELECTED_SS);
//    ui->THREE->setStyleSheet(UNSELECTED_SS);
//    ui->FOUR->setStyleSheet(UNSELECTED_SS);
//    ui->FIVE->setStyleSheet(UNSELECTED_SS);
//    ui->SIX->setStyleSheet(UNSELECTED_SS);
//    ui->SEVEN->setStyleSheet(UNSELECTED_SS);
//    ui->EIGHT->setStyleSheet(UNSELECTED_SS);
//    ui->NINE->setStyleSheet(UNSELECTED_SS);
//    ui->TEN->setStyleSheet(UNSELECTED_SS);
//    ui->ELEVEN->setStyleSheet(UNSELECTED_SS);
//    ui->TWELVE->setStyleSheet(UNSELECTED_SS);

//    ui->OCLOCK->setStyleSheet(UNSELECTED_SS);

    // Get all UI labels and apply colour
    QList<QLabel*> label_list_;
    label_list_ = this->findChildren<QLabel*>();
    foreach(QLabel *lbl, label_list_) {
        lbl->setStyleSheet(UNSELECTED_SS);
    }

}

void MainWindow::setTime(int hours, int minutes){
    const QString UNSELECTED_SS = "QLabel {color: #"+UNSELECTED_COLOUR+";}"; // UNHIGHLIGHTED COLOUR
    const QString SELECTED_SS = "QLabel {color: #"+SELECTED_COLOUR+";}"; // HIGHLIGHT COLOUR
    const QString SELECTED_SS1 = "QLabel {color: #"+SELECTED_COLOUR+";}"; // HIGHLIGHT COLOUR

    ui->ITLabel->setStyleSheet(SELECTED_SS);
    ui->ISLabel->setStyleSheet(SELECTED_SS);

    // MINUTES
    if(minutes >= 0 && minutes <= 4){
        ui->OCLOCK->setStyleSheet(SELECTED_SS1);
    }else if(minutes >= 5 && minutes <= 9){ //It is 5 past
        ui->FIVE_MIN->setStyleSheet(SELECTED_SS);
        ui->PAST->setStyleSheet(SELECTED_SS1);
    }else if(minutes >= 10 && minutes <= 14){ //It is 10 past
        ui->TEN_MIN->setStyleSheet(SELECTED_SS);
        ui->PAST->setStyleSheet(SELECTED_SS1);
    }else if(minutes >= 15 && minutes <= 19){ //It is quater past
        ui->QUARTER->setStyleSheet(SELECTED_SS);
        ui->PAST->setStyleSheet(SELECTED_SS1);
    }else if(minutes >= 20 && minutes <= 24){ //It is 20 minutes past
        ui->TWENTY->setStyleSheet(SELECTED_SS);
        ui->MINUTES->setStyleSheet(SELECTED_SS);
        ui->PAST->setStyleSheet(SELECTED_SS1);
    }else if(minutes >= 25 && minutes <= 29){ //It is 25 minutes past
        ui->TWENTY->setStyleSheet(SELECTED_SS);
        ui->FIVE_MIN->setStyleSheet(SELECTED_SS);
        ui->MINUTES->setStyleSheet(SELECTED_SS);
        ui->PAST->setStyleSheet(SELECTED_SS1);
    }else if(minutes >= 30 && minutes <= 34){ //It is half past
        ui->HALF->setStyleSheet(SELECTED_SS);
        ui->PAST->setStyleSheet(SELECTED_SS1);
    }else if(minutes >= 35 && minutes <= 39){ //It is 25 minutes to
        ui->TWENTY->setStyleSheet(SELECTED_SS);
        ui->FIVE_MIN->setStyleSheet(SELECTED_SS);
        ui->MINUTES->setStyleSheet(SELECTED_SS);
        ui->TO->setStyleSheet(SELECTED_SS);
    }else if(minutes >= 40 && minutes <= 44){ //It is 20 to
        ui->TWENTY->setStyleSheet(SELECTED_SS);
        ui->TO->setStyleSheet(SELECTED_SS);
    }else if(minutes >= 45 && minutes <= 49){ //It is quarter to
        ui->QUARTER->setStyleSheet(SELECTED_SS);
        ui->TO->setStyleSheet(SELECTED_SS);
    }else if(minutes >= 50 && minutes <= 54){ //It is 10 to
        ui->TEN_MIN->setStyleSheet(SELECTED_SS);
        ui->TO->setStyleSheet(SELECTED_SS);
    }else if(minutes >= 55 && minutes <= 59){ //It is 5 to
        ui->FIVE_MIN->setStyleSheet(SELECTED_SS);
        ui->TO->setStyleSheet(SELECTED_SS);
    }


    //HOURS
    if(minutes <= 34){
        if(hours == 1){
            ui->ONE->setStyleSheet(SELECTED_SS1);
        }else if(hours == 2){
            ui->TWO->setStyleSheet(SELECTED_SS1);
        }else if(hours == 3){
            ui->THREE->setStyleSheet(SELECTED_SS1);
        }else if(hours == 4){
            ui->FOUR->setStyleSheet(SELECTED_SS1);
        }else if(hours == 5){
            ui->FIVE->setStyleSheet(SELECTED_SS1);
        }else if(hours == 6){
            ui->SIX->setStyleSheet(SELECTED_SS1);
        }else if(hours == 7){
            ui->SEVEN->setStyleSheet(SELECTED_SS1);
        }else if(hours == 8){
            ui->EIGHT->setStyleSheet(SELECTED_SS1);
        }else if(hours == 9){
            ui->NINE->setStyleSheet(SELECTED_SS1);
        }else if(hours == 10){
            ui->TEN->setStyleSheet(SELECTED_SS1);
        }else if(hours == 11){
            ui->ELEVEN->setStyleSheet(SELECTED_SS1);
        }else if(hours == 12){
            ui->TWELVE->setStyleSheet(SELECTED_SS1);
        }
    }

    if(minutes > 34){
        if(hours == 1){
            ui->TWO->setStyleSheet(SELECTED_SS1);
        }else if(hours == 2){
            ui->THREE->setStyleSheet(SELECTED_SS1);
        }else if(hours == 3){
            ui->FOUR->setStyleSheet(SELECTED_SS1);
        }else if(hours == 4){
            ui->FIVE->setStyleSheet(SELECTED_SS1);
        }else if(hours == 5){
            ui->SIX->setStyleSheet(SELECTED_SS1);
        }else if(hours == 6){
            ui->SEVEN->setStyleSheet(SELECTED_SS1);
        }else if(hours == 7){
            ui->EIGHT->setStyleSheet(SELECTED_SS);
        }else if(hours == 8){
            ui->NINE->setStyleSheet(SELECTED_SS1);
        }else if(hours == 9){
            ui->TEN->setStyleSheet(SELECTED_SS1);
        }else if(hours == 10){
            ui->ELEVEN->setStyleSheet(SELECTED_SS1);
        }else if(hours == 11){
            ui->TWELVE->setStyleSheet(SELECTED_SS1);
        }else if(hours == 12){
            ui->ONE->setStyleSheet(SELECTED_SS1);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

