#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "draw.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void onMakeEgdePushButtonClicked();
signals:
    void edgeS(int, int);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton* getNodeButton();
    QPushButton* getEdgeButton();
    QLineEdit* getLeftEdit();
    QLineEdit* getRightEdit();
    Draw* getDraw();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
