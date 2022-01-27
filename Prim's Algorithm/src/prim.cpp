#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <memory>


const auto INF = 0x3f3f3f3f;

using iPair = std::pair<int, int>;

class Graph
{
    private:
        int m_numberOfVertices;
        std::list<iPair>* m_adjList;

    public:
        Graph(int numberOfVertices)
        {
            m_numberOfVertices = numberOfVertices;
            m_adjList = new std::list<iPair> [numberOfVertices];
        }

        // as per Resource Aquisition is Initiaization (RAII)
        // i have to delete the memory that i explicitly allocated
        // THANK YOU RAII
        ~Graph()
        {
            delete [] m_adjList;
        }

        void addEdge(int src, int dest, int weight)
        {
            m_adjList[src].push_back(std::make_pair(dest, weight));
            m_adjList[dest].push_back(std::make_pair(src, weight));
        }


        void primMST()
        {
            std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq;

            int src = 0;

            std::vector<int> keys(m_numberOfVertices, INF);
            std::vector<int> parents(m_numberOfVertices, -1);
            std::vector<bool> inMST(m_numberOfVertices, false);


            // Now i basically have to push_back the source and initalize its key to 0

            pq.push(std::make_pair(0, src));

            // Now we have to loop through the priority queue
            while(!pq.empty())
            {
                // Now we have to pop the top element from the priority queue
                iPair top = pq.top();
                pq.pop();

                // Now we have to check if the top element is in the MST
                // For clarity i wrote inMST[top.second] == true
                if(inMST[top.second] == true)
                    continue;

                // Now we have to add the top element to the MST
                inMST[top.second] = true;

                // Now we have to update the keys of the adjacent vertices of the top element
                for(auto it = m_adjList[top.second].begin(); it != m_adjList[top.second].end(); it++)
                {

                    // 'it' is an iterator of a list<iPair>
                    // we take out the values from the iterator
                    int vertex = it->first;
                    int weight = it->second;

                    // '!inMST[it->first]' is the same as 'inMST[it->first] == false'
                    if(!inMST[it->first] && it->second < keys[it->first])
                    {
                        keys[it->first] = it->second;
                        parents[it->first] = top.second;
                        pq.push(std::make_pair(it->second, it->first));
                    }
                }
            }

            printMST(parents, keys);
        }


    private:
        void printMST(std::vector<int> parents, std::vector<int> keys)
        {
            std::cout << "Edge \tWeight" << std::endl;
            for(int i = 1; i < parents.size(); i++)
            {
                std::cout << parents[i] << " - " << i << "\t" << keys[i] << std::endl;
            }
        }
};


struct OptimizationGraph
{
    static void addEdge(std::vector<iPair> adjList[], int src, int dest, int weight)
    {
        adjList[src].push_back(std::make_pair(dest, weight));
        adjList[dest].push_back(std::make_pair(src, weight));
    }

    static void primMST(std::vector<iPair> adjList[], int numberOfVertices)
    {
        std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq;
        int src = 0;

        std::vector<int> keys(numberOfVertices, INF);
        std::vector<int> parents(numberOfVertices, -1);
        std::vector<bool> inMST(numberOfVertices, false);

        pq.push(std::make_pair(0, src));
        keys[src] = 0;

        while (!pq.empty())
        {
            iPair top = pq.top();
            pq.pop();

            if (inMST[top.second] == true)
                continue;

            inMST[top.second] = true;

            for (auto elem : adjList[top])
            {
                int vertex = elem.first;
                int weight = elem.second;

                if (!inMST[vertex] && weight < keys[vertex])
                {
                    keys[vertex] = weight;
                    parents[vertex] = top.second;
                    pq.push(std::make_pair(weight, vertex));
                }
            }
        }

    }

};


int main()
{

    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.primMST();
}