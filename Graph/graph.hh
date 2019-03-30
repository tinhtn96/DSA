/*
 * Author: Tinh Nguyen
 * Date: 30/03/2019
 * Description: My graph class
*/

#ifndef GRAPH_CLASS_H
#define GRAPH_CLASS_H

#include <iostream>
#include <list>
#include <cstdint>

// This graph is described by adjacency list
class Graph 
{

public:
    Graph (uint32_t numVertices);
    ~Graph ();
    void addEdge(uint32_t vertice, uint32_t nextVertice);
    uint32_t getVerticesInGraph ();
    uint32_t getEdgesInGraph ();

private:
    uint32_t numVertices; // No. of vetices in graph
    uint32_t numEdges;
    std::list<std::uint32_t> *adjacencyList;
};

#endif // GRAPH_CLASS_H