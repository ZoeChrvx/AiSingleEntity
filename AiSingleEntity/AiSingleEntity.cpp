
#include <climits>
#include <iostream>
#include <ostream>
#include <limits>

int inf = std::numeric_limits<int>::max();
using namespace std;

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX;
    int ind;
              
    for(int k=0;k<7;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[7][7],int src) // adjacency matrix 
{
    int distance[7]; // // array to calculate the minimum distance for each node                             
    bool Tset[7];// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<7; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<7; k++)                           
    {
        int m=miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<7; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<7; k++)                      
    { 
        char str=65+k; 
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main()
{
    int graph[7][7]={
        {0, 10, 15, NULL, 30, NULL, NULL},
        {NULL, 0, NULL, NULL, NULL, 57, NULL},
        {15, NULL, 0, 16, NULL, NULL, 52},
        {NULL, NULL, 13, 0, NULL, NULL, NULL},
        {30, NULL, NULL, NULL, 0, 11, 34},
        {NULL, 49, NULL, NULL, 12, 0, NULL},
        {NULL, NULL, 63, NULL, 35, NULL, 0}};
    DijkstraAlgo(graph,0);
    return 0;                           
}