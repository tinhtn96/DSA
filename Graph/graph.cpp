#include "graph.hh"


Graph::Graph(uint32_t numVertices)
{
    this->numVertices = numVertices;
    adjacencyList = new std::list<ADJ_LIST_NODE>[numVertices];
    numEdges = 0;
}

Graph::~Graph(void)
{
    std::cout << "Destructor Graph is called" <<std::endl;
    if (adjacencyList != NULL)
    {
        delete [] adjacencyList;
    }
}

void Graph::addEdge(uint32_t vertice, uint32_t nextVertice, uint32_t weight)
{
    ADJ_LIST_NODE stAdjListNode;
    memset(&stAdjListNode, 0, sizeof(ADJ_LIST_NODE));
    stAdjListNode.vertice = nextVertice;
    stAdjListNode.weight = weight;
    adjacencyList[vertice].push_back(stAdjListNode);
}

// void Graph::addEdge(uint32_t vertice, uint32_t nextVertice)
// {
//     ADJ_LIST_NODE stAdjListNode;
//     memset(&stAdjListNode, 0, sizeof(ADJ_LIST_NODE));
//     stAdjListNode.vertice = nextVertice;

//     adjacencyList[vertice].push_back(stAdjListNode);
// }

uint32_t Graph::getVerticesInGraph()
{
    return this->numVertices;
}

uint32_t Graph::getEdgesInGraph()
{
    return numEdges;
}

uint32_t Graph::getDegreesOfVertice(uint32_t vertice)
{
    return adjacencyList[vertice].size();
}

std::list<ADJ_LIST_NODE>* Graph::getAdjacencyMatrix(void)
{
    std::list<ADJ_LIST_NODE> *adjMatrix = new std::list<ADJ_LIST_NODE>[numVertices];
    ADJ_LIST_NODE stTmp = {0};

    for(int matrixColumn = 0; matrixColumn < (int)numVertices; matrixColumn++)
    {
        for(int matrixRow = 0; matrixRow < (int)numVertices; matrixRow++)
        {
            for(auto itr : adjacencyList[matrixColumn])
            {
                stTmp.vertice = matrixRow;
                if((int)itr.vertice == matrixRow)
                {
                    stTmp.weight = itr.weight;
                    break;
                }

                stTmp.weight = 0;
            }
            adjMatrix[matrixRow].push_back(stTmp);
        }
    }
    return adjMatrix;
}

void Graph::removeVertice(uint32_t vertice)
{
    numVertices--;

}

void Graph::printGraph(void)
{
    std::cout <<"======= Print Graph =======" << std::endl;

    for(int verIndex = 0; verIndex < (int)numVertices; verIndex++)
    {
        std::cout << "Vertice is [" << verIndex << "]"<< std::endl;
        std::cout << verIndex;
        for (auto itr : adjacencyList[verIndex])
        {
            std::cout << "->" << itr.vertice;
        }
        std::cout << std::endl;
    }
    std::cout <<"===========================" << std::endl;
}

void Graph::printAdjMatrixOfGraph(void)
{
    std::cout << "<<<<<<<<<Adjacency Matrix>>>>>>>>>>" << std::endl;

    std::list<ADJ_LIST_NODE> *adjMatrix = getAdjacencyMatrix();

    for(int verIndex = 0; verIndex < (int)numVertices; verIndex++)
    {
        std::cout << "[\t";
        for (auto itr : adjMatrix[verIndex])
        {
            std::cout << itr.weight << "\t";
        }
        std::cout << "]";
        std::cout << std::endl;
    }
    std::cout <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    if(adjMatrix != NULL)
    {
        delete [] adjMatrix;
    }
}
