#include "graph.h"
#include <QPushButton>
#include <QRandomGenerator>
#include <QDateTime>
#include <QPair>
#include <QLine>
#include <iostream>

int count = 0;

int Node::get_x()
{
    return x;
}
int Node::get_y()
{
    return y;
}
int Node::get_n()
{
    return n;
}
int Node::get_show_n()
{
    return show_n;
}
bool Node::isHigh()
{
    return high;
}
void Node::set_x(const int t)
{
    x = t;
}
void Node::set_y(const int t)
{
    y = t;
}
void Node::set_n(const int t)
{
    n = t;
}
void Node::set_show_n(const int t)
{
    show_n = t;
}
void Node::setHigh()
{
    high = true;
}
void Node::setNotHigh()
{
    high = false;
}
void Node::drawNode()
{

}
Node::Node(const int xv, const int yv, const int nv)
{
    set_x(xv);
    set_y(yv);
    set_n(nv);
    set_show_n(0);
    setNotHigh();
}

bool Node::operator!= (const Node& n)
{
    return (this->get_n()!=n.n || this->isHigh() != n.high);
}



int sgn6(int x)
{
    if (x > 7)
    {
        return -1;
    }
    else if (x == 7)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}



void Graph::addEdge(int u, int v)
{
    AdjacencyList[u - 1].push_back(v - 1);
    AdjacencyList[v - 1].push_back(u - 1);
    QPoint uP = QPoint(Nodes[u - 1].get_x(), Nodes[u - 1].get_y());
    QPoint vP = QPoint(Nodes[v - 1].get_x(), Nodes[v - 1].get_y());
    QLine l = QLine(uP, vP);
    Edges.push_back(l);
    emit edgeAddedS(Edges);
}
void Graph::addNode()
{

    std::cout << "graph slot got called\n";
    int n, x, y;
    if (!Nodes.isEmpty())
    {
        n = Nodes.last().get_n() + 1;


        x = Nodes.last().get_x() + (100 * sgn6(n)) ;
        if (n > 6)
        {
        y = static_cast<int>(( 270 + sqrt(-x * x + 594 * x - 24705)));
        }
        else
        {
         y = static_cast<int>(( 270 - sqrt(-x * x + 594 * x - 24705)));
        }

    }
    else
    {
        n = 1;
        x = 47;
        y = static_cast<int>(270 - sqrt(-x * x + 594 * x - 24705));
    }

    Nodes.push_back(Node(x, y, n));
    AdjacencyList.push_back(QVector<int>());
    used.push_back(false);
    emit nodeAddedS(Nodes);
}

void Graph::DFS(int s, int d)
{

  if (used[s-1])
  {
      return;
  }
  count++;
  Nodes[s-1].setHigh();
  Nodes[s-1].set_show_n(count);
  used[s-1] = true;
  emit nodeAddedS(Nodes);
  emit callTimer();
  Nodes[s-1].setNotHigh();


  for (int u : AdjacencyList[s-1])
  {
      std::cout << count << "\n";

      DFS(u+1, d);
  }
  std::cout << "\n";




}
void Graph::reset()
{
    count = 0;
    for(int i = 0; i < this->used.length(); i++)
    {
        this->used[i] = false;
        Nodes[i].setNotHigh();
        Nodes[i].set_show_n(0);
    }
    emit nodeAddedS(Nodes);
}
