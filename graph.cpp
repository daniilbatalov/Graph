#include "graph.h"
#include <QPushButton>
#include <QRandomGenerator>
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

Node::Node(const int xv, const int yv, const int nv)
{
    set_x(xv);
    set_y(yv);
    set_n(nv);
    set_show_n(0);
}

bool Node::operator!= (const Node& n)
{
    return (this->get_n()!=n.n);
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
    int n, x, y;
    x = y = 0;
    if (!Nodes.isEmpty())
    {
        n = Nodes.last().get_n() + 1;
        if (n == 2)
        {
            x = 147;
            y = 138;
        }
        if (n == 3)
        {
            x = 247;
            y = 98;
        }
        if (n == 4)
        {
            x = 347;
            y = 98;
        }
        if (n == 5)
        {
            x = 447;
            y = 138;
        }
        if (n == 6)
        {
            x = 547;
            y = 238;
        }
        if (n == 7)
        {
            x = 447;
            y = 408;
        }
        if (n == 8)
        {
            x = 347;
            y = 478;
        }
        if (n == 9)
        {
            x = 297;
            y = 488;
        }
        if (n == 10)
        {
            x = 247;
            y = 458;
        }
        if (n == 11)
        {
            x = 147;
            y = 388;
        }
        if (n == 12)
        {
            x = 97;
            y = 333;
        }
    }
    else
    {
        n = 1;
        x = 47;
        y = 238;
    }

    Nodes.push_back(Node(x, y, n));
    AdjacencyList.push_back(QVector<int>());
    used.push_back(false);
    emit nodeAddedS(Nodes);
}

void Graph::DFS(int s)
{
  if (used[s-1])
  {
      return;
  }
  count++;
  Nodes[s-1].set_show_n(count);
  used[s-1] = true;
  emit nodeAddedS(Nodes);

  for (int u : AdjacencyList[s-1])
  {
      DFS(u+1);
  }
  std::cout << "\n";
}
