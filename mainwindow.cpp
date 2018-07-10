#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_num;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Push on number buttons
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(compute()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(compute()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(compute()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(compute()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(compute()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(compute()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(compute()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(compute()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(compute()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(compute()));
    //Push on devide button
    connect(ui->pushButton_devide,SIGNAL(clicked()),this,SLOT(math_op()));
    //Push on multiplication button
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(math_op()));
    //Push on add button
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_op()));
    //Push on minus button
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_op()));

    ui->pushButton_devide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Write a number on the calc screen
void MainWindow::compute(){
    QPushButton *button = (QPushButton *)sender();
    double num = (ui->resultField->text() + button->text()).toDouble();

    QString str = QString::number(num,'g',8);

    ui->resultField->setText(str);
}

//Add dot after number
void MainWindow::on_pushButton_dot_clicked()
{
    if(!ui->resultField->text().contains(".")){
        ui->resultField->setText(ui->resultField->text() + ".");
    }
}

//Reset
void MainWindow::on_pushButton_AC_clicked()
{
    ui->resultField->setText("");
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_devide->setChecked(false);
    ui->pushButton_mult->setChecked(false);
}

//Change the sign of a number
void MainWindow::on_pushButton_sign_clicked()
{
    double num = ui->resultField->text().toDouble();
    num *= -1;

    QString str = QString::number(num,'g',8);

    ui->resultField->setText(str);
}

//Find percent
void MainWindow::on_pushButton_prosent_clicked()
{
    double num = ui->resultField->text().toDouble();
    num *= 0.01;

    QString str = QString::number(num,'g',8);

    ui->resultField->setText(str);
}

//Calcuate the result of the operation
void MainWindow::on_pushButton_ravno_clicked()
{
    double resNum = 0, second_num;
    second_num = ui->resultField->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        resNum = first_num + second_num;
        ui->pushButton_plus->setChecked(false);

    }else if(ui->pushButton_devide->isChecked()){
        if(second_num != 0){
            resNum = first_num / second_num;
            ui->pushButton_devide->setChecked(false);
        }
    }else if(ui->pushButton_minus->isChecked()){
        resNum = first_num - second_num;
        ui->pushButton_minus->setChecked(false);
    }else if(ui->pushButton_mult->isChecked()){
        resNum = first_num * second_num;
        ui->pushButton_mult->setChecked(false);
    }
    ui->resultField->setText(QString::number(resNum,'g',8));
}

//Select the operation
void MainWindow::math_op(){
    QPushButton *button = (QPushButton *)sender();
    button->setChecked(true);
    first_num = ui->resultField->text().toDouble();
    ui->resultField->setText("");



}
