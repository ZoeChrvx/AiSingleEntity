#include <vector>

void Dijkstra(int graph[][], int nodesCount, int src)
{
    int dist[nodesCount];
    int prev[nodesCount][nodesCount];
    std::vector<int> set;
    
    for(int v = 0; v<nodesCount; v++)
    {
        dist[v] = INT_MAX;
        prev[v] = {};
        set.emplace_back(v);
    }
    dist[src]=0;

    while(!std::empty(set))
    {
         
    }
}
