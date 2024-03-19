
#include <climits>
#include <iostream>
#include <ostream>
#include <limits>
#include <vector>

int inf = std::numeric_limits<int>::max();
int steps;
constexpr int nodes_count = 7;
using namespace std;

void Result(int dist[])
{
    cout<<"Vertex\t\tDistance from source vertex"<< '\n';
    for(int v = 0; v<nodes_count; v++)                      
    { 
        char str=65+v; 
        cout<<str<<"\t\t\t"<<dist[v]<< '\n';
    }
}

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX;
    int minDist = 0;
              
    for(int v=0;v<nodes_count;v++) 
    {
        if(Tset[v]==false && distance[v]<=minimum)      
        {
            minimum=distance[v];
            minDist=v;
        }
    }
    return minDist;
}

void Dijkstra(int graph[nodes_count][nodes_count], int src)
{
    int dist[nodes_count];
    bool prev[nodes_count];
    
    //Q = set
    vector<int> set;
    
    for(int v = 0; v<nodes_count; v++)
    {
        dist[v] = INT_MAX;
        prev[v] = false;
        set.emplace_back(v);

    }
    dist[src]=0;

    for(int v=0; v< nodes_count; v++)
    {
        int m = miniDist(dist, prev);
        prev[m]=true;
        for(int v = 0; v<nodes_count;v++)
        { 
            if(!prev[v] && graph[m][v] && dist[m] != INT_MAX && dist[m]+graph[m][v] < dist[v])
            {
                dist[v]=dist[m]+graph[m][v];
            }
        }
    }

    Result(dist);
}


int main()
{
    int graph[nodes_count][nodes_count] = {
        {0, 10, 15, NULL, 30, NULL, NULL},
        {NULL, 0, NULL, NULL, NULL, 57, NULL},
        {15, NULL, 0, 16, NULL, NULL, 52},
        {NULL, NULL, 13, 0, NULL, NULL, NULL},
        {30, NULL, NULL, NULL, 0, 11, 34},
        {NULL, 49, NULL, NULL, 12, 0, NULL},
        {NULL, NULL, 63, NULL, 35, NULL, 0}
    };
    Dijkstra(graph,2);                        
}