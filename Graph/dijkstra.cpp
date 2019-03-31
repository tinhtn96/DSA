#include "algorithm.hh"

Algorithm::~Algorithm()
{

}

bool Algorithm::sortByWeight(const std::pair<uint32_t, uint32_t> &a, const std::pair<uint32_t, uint32_t> &b)
{ 
    return (a.first < b.first);
} 

int Algorithm::dijkstra(uint32_t srcVertice)
{
    std::cout << "========= Dijkstra ==========" << std::endl;

    std::set<std::pair<uint32_t, uint32_t>> setds;

    // std::vector<std::pair<uint32_t, uint32_t>> vecds;

    std::vector<uint32_t> distance(getVerticesInGraph(), INT_MAX);
    // Initialize first step
    setds.insert(std::make_pair(0, srcVertice));
    distance[srcVertice] = 0;

    while(!setds.empty())
    {
        std::pair<uint32_t, uint32_t> tmp = *(setds.begin()); // the distance was sorted
        setds.erase(setds.begin()); 

        uint32_t u = tmp.second;
        
        std::list<ADJ_LIST_NODE> tmpList = adjacencyList[u];
        for(auto itr : tmpList)
        {
            uint32_t v = itr.vertice;
            uint32_t w = itr.weight;

            if(distance[v] > distance[u] + w)
            {
                if(distance[v] != INT_MAX)
                {
                    setds.erase(setds.find(std::make_pair(distance[v], v)));
                }

                distance[v] = distance[u] + w;
                setds.insert(std::make_pair(distance[v], v));
            }
        }
    }

    for(int i = 0; i < (int)getVerticesInGraph(); i++)
    {
        std::cout << i << "\t\t"<< distance[i] << std::endl;
    }

    std::cout << "========== Paths way ==========" << std::endl;

    std::list<uint32_t> pathList[getVerticesInGraph()];


    for(int i = 0; i < (int)getVerticesInGraph(); i++)
    {
        bool flag = false;
        std::cout << i << "->";
        if(i == (int)srcVertice)
        {
            pathList[i].push_back(srcVertice);
            std::cout << i << "->";
        }
        else
        {
            int tmp = -1;
            while(tmp != (int)srcVertice)
            {
                std::list<ADJ_LIST_NODE> tmpList;
                uint32_t index;
                if(!flag)
                {
                    tmpList = adjacencyList[i];
                    index = i;
                }
                else
                {
                    tmpList = adjacencyList[tmp];
                    index = tmp;
                }

                for(auto itr : tmpList)
                {
                    if(distance[index] - distance[itr.vertice] == itr.weight)
                    {
                        pathList[index].push_back(itr.vertice);
                        tmp = itr.vertice;
                        std::cout << tmp << "->";
                        break;
                    }
                }
                flag = true;

            }
        }
        std::cout << std::endl;
    }


    return 0;
}
