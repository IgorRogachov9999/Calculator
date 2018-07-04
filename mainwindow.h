#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    Ui::MainWindow *ui;

private slots:
    void compute();
    void on_pushButton_dot_clicked();
    void on_pushButton_AC_clicked();
    void on_pushButton_sign_clicked();
    void on_pushButton_prosent_clicked();
    void on_pushButton_ravno_clicked();
    void math_op();
};

#endif // MAINWINDOW_H
