#include "Test.h"
#include <iostream>

using namespace std;

int countwalks(int** graph, int u, int v, int k, int V)
{
    int count[V][V][k+1];

    for (int e = 0; e < k+1; e++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                count[i][j][e] = 0;

                if (e == 0 && i == j)
                    count[i][j][e] = 1;
                if (e == 1 && graph[i][j])
                    count[i][j][e] = 1;

                if (e > 1)
                {
                    for (int a = 0; a < V; a++)
                        if (graph[i][a])
                            count[i][j][e] += count[a][j][e-1];
                }
           }
        }
    }
    return count[u][v][k];
}

int countPaths(int** DAG, int size, int origin, int destination)
{
    int k = 0;
    for(int i = 0 ;i < size ; i++){
        for(int j = 0; j < size;j++) {
            if(DAG[i][j] != -1){
                k++;
            }
        }
    }
    return countwalks(DAG, origin, destination, k, size);
}

//Returns a vector that maps each vertex to a color (or number)
//Two adjacent vertex cannot have the same color
//The less colors used, the better
//Use a Greedy Paradigm to optimize the process
//The best solution is not required
vector<int> getVertexColors(int** graph, int size)
{
    vector<int> answer;
    return answer;
}

int main ()
{
    test();
    return 0;
}
