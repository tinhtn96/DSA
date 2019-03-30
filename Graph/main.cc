#include "graph.hh"

int main (void)
{
    std::cout << ">>>>>>>>>>>>>MAIN<<<<<<<<<<<<<<"<< std::endl
              << "This is a test for simple graph"<< std::endl
              <<  ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<< std::endl;

    Graph *simpleGraph = new Graph(5);

    simpleGraph->addEdge(2, 3, 3);
    simpleGraph->addEdge(2, 4, 9);
    simpleGraph->addEdge(3, 2, 3);
    simpleGraph->addEdge(3, 4, 1);
    simpleGraph->addEdge(4, 0, 6);
    simpleGraph->addEdge(4, 2, 9);
    simpleGraph->addEdge(4, 3, 1);
    simpleGraph->addEdge(0, 1, 2);
    simpleGraph->addEdge(0, 2, 2);


    simpleGraph->printGraph();
    std::cout << "Degree of 2 is " << simpleGraph->getDegreesOfVertice(2) << std::endl;
    simpleGraph->printAdjMatrixOfGraph();

    simpleGraph->addEdge(0, 4, 6);
    simpleGraph->addEdge(1, 0, 2);
    simpleGraph->addEdge(2, 0, 2);
    std::cout << "Degree of 2 is " << simpleGraph->getDegreesOfVertice(2) << std::endl;
    simpleGraph->printAdjMatrixOfGraph();

    if(simpleGraph != NULL)
    {
        delete simpleGraph;
    }
}