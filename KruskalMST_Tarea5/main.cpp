#include "Test.h"
#include <iostream>
#include "Edge.h"

using namespace std;

map<int,bool> visited;

int** initializeGraph(int size)
{
    int **answer = new int* [size];
    for(int i=0;i<size;i++)
    {
        answer[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            answer[i][j]=-1;
        }
    }
    return answer;
}

int** mapEdgesToGraph(vector<Edge *> edges, int size) {

    int** graph = initializeGraph(size);
    int index = 0;

    while (index < edges.size())
    {
        graph[edges[index]->source][edges[index]->destination] = edges[index]->weight;
        graph[edges[index]->destination][edges[index]->source] = edges[index]->weight;
        index++;
    }

    return graph;
}

int** getKruskalMST(int** graph, int size, vector<Edge*> edges)
{
    visited.clear();
    vector<Edge *> T;
    int index = 0;

    while(index < edges.size())
    {
        if(!(visited[edges[index]->source] && visited[edges[index]->destination])) {
            visited[edges[index]->source] = true;
            visited[edges[index]->destination] = true;
            T.push_back(edges[index]);
        }
        index++;
    }

    return mapEdgesToGraph(T, size);
}
int main ()
{
    test();
    return 0;
}
