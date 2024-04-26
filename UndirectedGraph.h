#ifndef UndirectedGraph_h
#define UndirectedGraph_h
#include <unordered_map>
#include <iostream>
#include "vector.h"

#include "Graph.h"

using namespace std;

class UndirectedGraph : public Graph {
private:
    unordered_map<int, unordered_map<int, int>> weights; // Хранилище весов ребер
    unordered_map<int, vector<int>> adjList;
    //unordered_map - списки смежности для каждой вершины
public:
    void addVertex(int vertex) override {
        if (!hasVertex(vertex)) {
            adjList[vertex] = vector<int>(); // добавляем вершину в список смежности
        }
    }

    void addEdge(int vertex1, int vertex2, int weight) override {
        if (!hasEdge(vertex1, vertex2)) {
            adjList[vertex1].push_back(vertex2);
            adjList[vertex2].push_back(vertex1); // добавляем вершину в список смежности для первой вершины (тк граф неориентированный)
            weights[vertex1][vertex2] = weight; // Сохраняем вес ребра
        }
    }

    int getWeight(int vertex1, int vertex2) override {
        if (hasEdge(vertex1, vertex2)) 
        {
          return weights[vertex1][vertex2]; // Возвращаем вес ребра
        }
        return -1;
    }

    void removeVertex(int vertex) override {
        if (hasVertex(vertex)) {
            for (int v : adjList[vertex]) {
                removeEdge(vertex, v);
            }
            adjList.erase(vertex); // удаляем вершину из списка смежности
        }
    }

    void removeEdge(int vertex1, int vertex2) override {
        if (hasEdge(vertex1, vertex2)) {
            adjList[vertex1].erase(remove(adjList[vertex1].begin(), adjList[vertex1].end(), vertex2), adjList[vertex1].end()); // удаляем вершину из списка смежности для другой вершины
            adjList[vertex2].erase(remove(adjList[vertex2].begin(), adjList[vertex2].end(), vertex1), adjList[vertex2].end()); // удаляем вершину из списка смежности для первой вершины
        }
    }

    bool hasVertex(int vertex) override {
        return adjList.find(vertex) != adjList.end();
    }

    bool hasEdge(int vertex1, int vertex2) override {
        if (hasVertex(vertex1) && hasVertex(vertex2)) {
            for (int v : adjList[vertex1]) {
                if (v == vertex2) {
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> getNeighbors(int vertex) override {
        if (hasVertex(vertex)) {
            return adjList[vertex];
        }
        return vector<int>();
    }

    vector<int> getVertices() override {
        vector<int> vertices;
        for (auto const& [vertex, neighbors] : adjList) { // // проходим по списку смежности
            vertices.push_back(vertex); // добавляем
        }
        return vertices;
    }
};



#endif
