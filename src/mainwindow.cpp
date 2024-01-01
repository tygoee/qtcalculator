#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::initializer_list<QPushButton *> numbers = {
        ui->pushButton_0,
        ui->pushButton_1,
        ui->pushButton_2,
        ui->pushButton_3,
        ui->pushButton_4,
        ui->pushButton_5,
        ui->pushButton_6,
        ui->pushButton_7,
        ui->pushButton_8,
        ui->pushButton_9,
    };

    for (QPushButton *const &pushButton : numbers)
    {
        connect(pushButton, SIGNAL(released()), this, SLOT(digit_pressed()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton *button = (QPushButton *)sender();

    double number = (ui->label->text() + button->text()).toDouble();

    ui->label->setText(QString::number(number));
}