#include <QPainter>
#include "draw.h"
#include <QPoint>
#include <QLine>
#include <iostream>
Draw::Draw(QWidget *parent) : QWidget(parent){};
void Draw::paintEvent(QPaintEvent *e)
{
  Q_UNUSED(e);
  doPainting();
}

void Draw::doPainting()
{
  QPainter painter(this);
  painter.setPen(Qt::blue);
  painter.setBrush(QBrush("#ffffff"));
  for(auto e : edges)
  {
      painter.drawLine(e);
  }
  for(auto n : nodes)
  {
      painter.drawEllipse(QPoint(n.get_x(), n.get_y()), 20, 20);
      painter.drawText(QRectF(n.get_x() - 20, n.get_y() - 20, 40, 40), Qt::AlignCenter, QString("%1").arg(n.get_n()));
  }
}

void Draw::drawN(QVector<Node> d)
{
    //std::cout << "draw slot got called\n";
    if (!d.isEmpty())
    {
        if ((nodes.isEmpty() || nodes.last() != d.last()))
        {
            //std::cout << "update\n";
            nodes = d;
            update();
        }
    }
}
void Draw::drawE(QVector<QLine> d)
{
    //std::cout << "draw slot got called\n";
    if (!d.isEmpty())
    {
        if ((edges.isEmpty() || edges.last() != d.last()))
        {
            //std::cout << "update\n";
            edges = d;
            update();
            emit drawnE();
        }
    }
}
