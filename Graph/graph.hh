/*
 * Author: Tinh Nguyen
 * Date: 30/03/2019
 * Description: My graph class
*/

#ifndef GRAPH_CLASS_H
#define GRAPH_CLASS_H

#include <iostream>
#include <list>
#include <map>
#include <cstdint>
#include <bits/stdc++.h>

// This graph is described by adjacency list (undirected or directed graph)

typedef struct
{
    uint32_t vertice;
    uint32_t weight;
}ADJ_LIST_NODE;

class Graph 
{

public:
    Graph(uint32_t numVertices);
    ~Graph(void);
    void addEdge(uint32_t vertice, uint32_t nextVertice, uint32_t weight);
    void addEdge(uint32_t vertice, uint32_t nextVertice);
    uint32_t getVerticesInGraph(void);
    uint32_t getEdgesInGraph(void);
    uint32_t getDegreesOfVertice(uint32_t vertice);
    std::list<ADJ_LIST_NODE>* getAdjacencyMatrix(void);
    void removeVertice(uint32_t vertice);

    // Test
    void printGraph(void);
    void printAdjMatrixOfGraph(void);

private:
    uint32_t numVertices; // No. of vetices in graph
    uint32_t numEdges;    // No. of edges in graph
    std::list<ADJ_LIST_NODE> *adjacencyList; // List array

    std::list<std::list<ADJ_LIST_NODE>> adjacencyNestedList;
    std::map<std::string, uint32_t> mapVerConvert;
};

#endif // GRAPH_CLASS_H