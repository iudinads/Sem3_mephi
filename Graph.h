#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

using namespace std;

class Graph {
public:
    virtual void addVertex(int vertex) = 0;
    virtual void addEdge(int vertex1, int vertex2, int weight) = 0;
    virtual int getWeight(int vertex1, int vertex2) = 0;
    virtual void removeVertex(int vertex) = 0;
    virtual void removeEdge(int vertex1, int vertex2) = 0;
    virtual bool hasVertex(int vertex) = 0;
    virtual bool hasEdge(int vertex1, int vertex2) = 0;
    virtual vector<int> getNeighbors(int vertex) = 0;
    virtual vector<int> getVertices() = 0;

};


#endif
