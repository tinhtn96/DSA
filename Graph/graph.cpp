#include "graph.hh"

Graph::Graph (uint32_t numVertices)
{
    this->numVertices = numVertices;
    adjacencyList = new std::list<uint32_t>[numVertices];
    numEdges = 0;
}

Graph::~Graph ()
{
    if (adjacencyList != NULL)
    {
        delete adjacencyList;
    }
}

void Graph::addEdge(uint32_t vertice, uint32_t nextVertice)
{
    adjacencyList[vertice].push_back(nextVertice);
}

uint32_t Graph::getVerticesInGraph ()
{
    return numVertices;
}

uint32_t Graph::getEdgesInGraph ()
{
    return numEdges;
}