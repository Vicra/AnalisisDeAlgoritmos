#include "Test.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Edge.h"

using namespace std;


int* getShortestPath(int** graph, int size, int src)
{
    int V = size;

    vector<Edge> edges;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(graph[i][j] != -1){
                Edge edge(i,j,graph[i][j]);
                edges.push_back(edge);
            }
        }
    }

    int E = edges.size();
    int dist[size];
    int* predecesor = new int[size];
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        predecesor[i]= NULL;
    }
    dist[src] = 0;
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                predecesor[v] = u;
            }
        }
    }

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle");
    }

    return predecesor;
}

int main ()
{
    test();
    return 0;
}
