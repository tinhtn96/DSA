#include "algorithm.hh"

int main (void)
{
    std::cout << ">>>>>>>>>>>>>MAIN<<<<<<<<<<<<<<"<< std::endl
              << "This is a test for simple graph"<< std::endl
              <<  ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<< std::endl;

    // Graph *simpleGraph = new Graph(5);

    // simpleGraph->addEdge(2, 3, 3);
    // simpleGraph->addEdge(2, 4, 9);
    // simpleGraph->addEdge(3, 2, 3);
    // simpleGraph->addEdge(3, 4, 1);
    // simpleGraph->addEdge(4, 0, 6);
    // simpleGraph->addEdge(4, 2, 9);
    // simpleGraph->addEdge(4, 3, 1);
    // simpleGraph->addEdge(0, 1, 2);
    // simpleGraph->addEdge(0, 2, 2);

    // simpleGraph->printGraph();
    // std::cout << "Degree of 2 is " << simpleGraph->getDegreesOfVertice(2) << std::endl;
    // simpleGraph->printAdjMatrixOfGraph();

    // if(simpleGraph != NULL)
    // {
    //     delete simpleGraph;
    // }


    Algorithm *testAlgorithm = new Algorithm(7);

    testAlgorithm->addEdge(0, 1, 4);
    testAlgorithm->addEdge(0, 3, 1);

    testAlgorithm->addEdge(1, 2, 5);
    testAlgorithm->addEdge(1, 4, 4);
    testAlgorithm->addEdge(1, 3, 10);
    testAlgorithm->addEdge(1, 0, 4);

    testAlgorithm->addEdge(2, 1, 5);
    testAlgorithm->addEdge(2, 4, 1);

    testAlgorithm->addEdge(3, 0, 1);
    testAlgorithm->addEdge(3, 1, 10);
    testAlgorithm->addEdge(3, 6, 3);

    testAlgorithm->addEdge(4, 1, 4);
    testAlgorithm->addEdge(4, 2, 1);
    testAlgorithm->addEdge(4, 5, 10);
    testAlgorithm->addEdge(4, 6, 5);

    testAlgorithm->addEdge(5, 4, 10);
    testAlgorithm->addEdge(5, 6, 10);

    testAlgorithm->addEdge(6, 4, 5);
    testAlgorithm->addEdge(6, 5, 10);
    testAlgorithm->addEdge(6, 3, 3);

    testAlgorithm->printAdjMatrixOfGraph();

    testAlgorithm->dijkstra(4);

    if(testAlgorithm != NULL)
    {
        delete testAlgorithm;
    }
}