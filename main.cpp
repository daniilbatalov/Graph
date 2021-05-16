#include <QApplication>
#include <QWidget>
#include <QFrame>
#include <QGridLayout>
#include <QGraphicsView>
#include <iostream>
#include "mainwindow.h"
#include "draw.h"
#include "graph.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);
  Graph graph;
  MainWindow window;
  QPushButton* psh = window.getNodeButton();
  QPushButton* vrg = window.getEdgeButton();
  QLineEdit* lftdt = window.getLeftEdit();
  QLineEdit* rgtdt = window.getRightEdit();
  Draw* dr = window.getDraw();
  QObject::connect(psh, &QPushButton::clicked, &graph, &Graph::addNode);
  QObject::connect(&graph, &Graph::nodeAddedS, dr, &Draw::drawN);

  QObject::connect(vrg, &QPushButton::clicked, &window, &MainWindow::onMakeEgdePushButtonClicked);
  QObject::connect(&window, &MainWindow::edgeS, &graph,  &Graph::addEdge);
  QObject::connect(&graph, &Graph::edgeAddedS, dr, &Draw::drawE);
  QObject::connect(dr, &Draw::drawnE, lftdt, &QLineEdit::clear);
  QObject::connect(dr, &Draw::drawnE, rgtdt, &QLineEdit::clear);
  window.show();

  return app.exec();
}
