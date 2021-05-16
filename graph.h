#ifndef GRAPH_H
#define GRAPH_H
#include <QObject>
#include <QVector>
#include <QPair>
#include <QLine>
class Node
{
private:
    int x, y, n;
public:
    int get_x();
    int get_y();
    int get_n();
    void set_x(const int);
    void set_y(const int);
    void set_n(const int);
    void drawNode();
    Node(const int, const int, const int);
    bool operator!= (const Node&);
};

class Graph : public QObject
{
    Q_OBJECT
public:
    QVector<Node> Nodes;
    QVector<QLine> Edges;
    Graph(){};
    ~Graph(){};
public slots:
    void addEdge(int, int);
    void addNode();
signals:
    void edgeAddedS(const QVector<QLine>);
    void nodeAddedS(const QVector<Node>);
private:
    QVector<QVector<int>> AdjacencyList;
    QVector<bool> used;
};


#endif // GRAPH_H
