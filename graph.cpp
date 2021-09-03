#include "graph.h"
#include <QPushButton>
#include <QRandomGenerator>
#include <QDateTime>
#include <QPair>
#include <QLine>
#include <iostream>

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
void Node::drawNode()
{

}
Node::Node(const int xv, const int yv, const int nv)
{
    set_x(xv);
    set_y(yv);
    set_n(nv);
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
    QRandomGenerator gen1 =  QRandomGenerator();
    gen1.seed(QDateTime::currentMSecsSinceEpoch());
    std::cout << "graph slot got called\n";
    int n, x, y;
    if (!Nodes.isEmpty())
    {
        n = Nodes.last().get_n() + 1;

        x = Nodes.last().get_x() + 100;
        if (n > 5)
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
    AdjacencyList.append(QVector<int>(0));
    emit nodeAddedS(Nodes);
}
