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
    void goS(int);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton* getNodeButton();
    QPushButton* getEdgeButton();
    QLineEdit* getLeftEdit();
    QLineEdit* getRightEdit();
    Draw* getDraw();
    Draw* getDrawR();

private slots:
    void on_goButton_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
