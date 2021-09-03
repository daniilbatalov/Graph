#include "mainwindow.h"
#include "ui_mainwindow.h"

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
