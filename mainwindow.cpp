#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
QPushButton* MainWindow::getNodeButton()
{
    return ui->nodeButton;
}
QPushButton* MainWindow::getEdgeButton()
{
    return ui->vergeButton;
}
QLineEdit* MainWindow::getLeftEdit()
{
    return ui->leftEdit;
}
QLineEdit* MainWindow::getRightEdit()
{
    return ui->rightEdit;
}
Draw* MainWindow::getDraw()
{
    return ui->widget;
}
Draw* MainWindow::getDrawR()
{
    return ui->widget_2;
}
int MainWindow::getSpeed()
{
    return this->speed;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMakeEgdePushButtonClicked()
{
    QVector<QLineEdit*> lineEdits = {ui->leftEdit, ui->rightEdit};
    QVector<int> values;

    for (const QLineEdit* lineEdit : lineEdits)
    {
        bool ok = false;
        int value = lineEdit->text().toInt(&ok);
        if (ok)
        {
            values.push_back(value);
        }
    }


    if (values.empty())
    {

    }
    else
    {
        emit edgeS(values[0], values[1]);
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    speed = value - speed;
}

void MainWindow::on_goButton_clicked()
{
    QLineEdit* line = ui->goLineEdit;
    int value = line->text().toInt();
    line->clear();
    emit goS(value);
}

void MainWindow::on_resetButton_clicked()
{
    ui->label_3->setText("Выполнено!");
    QEventLoop el;
    QTimer t;
    connect(&t, SIGNAL(timeout()), &el, SLOT(quit()));
    t.start(2000);
    el.exec();
    ui->label_3->setText("");
    emit resetS();
}
void MainWindow::pause()
{
    QEventLoop el;
    QTimer t;
    connect(&t, SIGNAL(timeout()), &el, SLOT(quit()));
    t.start(speed);
    el.exec();
    return;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    ui->label_2->setText(QString("Скорость визуализации: %1 с").arg((static_cast<float>(position)) / 1000));
}
