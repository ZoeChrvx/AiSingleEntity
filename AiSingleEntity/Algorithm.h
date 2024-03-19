#include <vector>

void Dijkstra(int graph[][], int nodesCount, int src)
{
    int dist[nodesCount];
    int pred[nodesCount][nodesCount];
    
    //Q = set
    std::vector<int> set;
    
    for(int v = 0; v<nodesCount; v++)
    {
        dist[v] = INT_MAX;
        pred[v] = {};
        set.emplace_back(v);
    }
    dist[src]=0;

    while(!std::empty(set))
    {
        int minDist = INT_MIN;
        int minNode = -1;

        for(int v : set)
        {
            if(dist[v] < minDist)
            {
                minDist = dist[v];
                minNode=v;
            }
        }

        if(minNode == -1) break;

        set.erase(std::remove(set.begin(), set.end(), minNode), set.end());
        for(int v = 0;v<nodesCount;v++)
        {
            if(graph[minNode][v]!=0)
            {
                int alt = dist[minNode] + graph[minNode][v];
                if(alt < dist[v])
                {
                    dist[v] = alt;
                }
            }
        }
    }
}
