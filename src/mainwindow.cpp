#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::initializer_list<QPushButton *> numbers = {
        ui->pushButton_1, ui->pushButton_2, ui->pushButton_3,
        ui->pushButton_4, ui->pushButton_5, ui->pushButton_6,
        ui->pushButton_7, ui->pushButton_8, ui->pushButton_9,
        ui->pushButton_0};

    std::initializer_list<QPushButton *> unary_operators = {
        ui->pushButton_invert, ui->pushButton_percent};

    for (QPushButton *const &pushButton : numbers)
    {
        connect(pushButton, SIGNAL(released()), this, SLOT(digit_released()));
    }

    for (QPushButton *const &pushButton : unary_operators)
    {
        connect(pushButton, SIGNAL(released()), this, SLOT(unary_operator_released()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_released()
{
    QPushButton *button = (QPushButton *)sender();
    double number = (ui->label->text() + button->text()).toDouble();

    ui->label->setText(QString::number(number, 'g', 15));
}

void MainWindow::unary_operator_released()
{
    QPushButton *button = (QPushButton *)sender();
    double number = ui->label->text().toDouble();

    if (button == ui->pushButton_invert)
    {
        number = number * -1;
    }
    else if (button == ui->pushButton_percent)
    {
        number = number * 0.01;
    }

    ui->label->setText(QString::number(number));
}

void MainWindow::binary_operation_released()
{
}

void MainWindow::on_pushButton_clear_released()
{
    ui->label->setText("0");
}

void MainWindow::on_pushButton_decimal_released()
{
    QString text = ui->label->text();

    if (!text.contains('.'))
    {
        ui->label->setText(text + ".");
    }
}