#ifndef DirectedGraph_h
#define DirectedGraph_h
#include <unordered_map>
#include <iostream>
#include "Graph.h"
#include "vector.h"


using namespace std;

class DirectedGraph : public Graph {
private:
    unordered_map<int, unordered_map<int, int>> weights; // Хранилище весов ребер
    unordered_map<int, vector<int>> adjList;
    // unordered_map - содержит списки смежности для каждой вершины

public:
    void addVertex(int vertex) override {
        if (!hasVertex(vertex)) {
            adjList[vertex] = vector<int>(); //добавляем в список смежности
        }
    }

    void addEdge(int vertex1, int vertex2, int weight) override {
        if (!hasEdge(vertex1, vertex2)) {
            adjList[vertex1].push_back(vertex2); 
            weights[vertex1][vertex2] = weight; // Сохраняем вес ребра
            // добавляем вершину в список смежности для другой вершины
        }
        

    }

    int getWeight(int vertex1, int vertex2) override {
        if (hasEdge(vertex1, vertex2)) 
        {
          return weights[vertex1][vertex2]; // Возвращаем вес ребра
        }
    // Если ребро не существует, можно бросить исключение или вернуть некоторое стандартное значение, например -1
        return -1;
    }

    void removeVertex(int vertex) override {
        if (hasVertex(vertex)) {
            for (auto const& [v, neighbors] : adjList) {
                removeEdge(v, vertex); // все ребра связанные с данной вершиной
            }
            adjList.erase(vertex); //удаляем из списка см
        }
    }

    void removeEdge(int vertex1, int vertex2) override {
        if (hasEdge(vertex1, vertex2)) {
           adjList[vertex1].erase(remove(adjList[vertex1].begin(), adjList[vertex1].end(), vertex2), adjList[vertex1].end());
           // удаляем вершину из списка смежности для другой вершины
        }
    }

    bool hasVertex(int vertex) override {
        return adjList.find(vertex) != adjList.end();
    }

    bool hasEdge(int vertex1, int vertex2) override {
        if (hasVertex(vertex1) && hasVertex(vertex2)) {
            for (int v : adjList[vertex1]) { // проходим по списку смежности для первой вершины
                if (v == vertex2) { 
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> getNeighbors(int vertex) override { // метод получения списка смежности для заданной вершины
        if (hasVertex(vertex)) {
            return adjList[vertex];
        }
        return vector<int>();
    }

    vector<int> getVertices() override {
        vector<int> vertices;
        for (auto const& [vertex, neighbors] : adjList) {
            vertices.push_back(vertex);
        }
        return vertices;
    }

};


#endif
