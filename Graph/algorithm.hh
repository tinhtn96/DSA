/*
 * Author: Tinh Nguyen
 * Date: 30/03/2019
 * Description: My algorithms class
*/

#ifndef ALGORITHMS_CLASS_H
#define ALGORITHMS_CLASS_H

#include "graph.hh"

class Algorithm : public Graph 
{
public:
    // Algorithms
    Algorithm(uint32_t numVerticesOfGraph):Graph(numVerticesOfGraph)
    {
        std::cout << "Algorithm class is called " << std::endl;
    }

    ~Algorithm();

    // Algorithms
    int dijkstra(uint32_t srcVertice);
    
private:
    // Dijkstra algorithm
    static bool sortByWeight(const std::pair<uint32_t,uint32_t> &a, const std::pair<uint32_t,uint32_t> &b);
};

#endif //ALGORITHMS_CLASS_H
