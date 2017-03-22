#include "Test.h"

int** _initGraph(int size)
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

bool _checkColors(int **graph, int size, vector<int> colors)
{
    if(size!=colors.size())
        return false;

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(graph[i][j]!=-1 || graph[j][i]!=-1)
            {
                if(colors[i]==colors[j])
                    return false;
            }
        }
    }
    return true;
}

int _countColors(vector<int> colors)
{
    set<int> my_set;
    for(int i=0;i<colors.size();i++)
        my_set.insert(colors[i]);
    return my_set.size();
}

void test()
{
    int** graph1 = _initGraph(5);
    graph1[0][1]=99;
    graph1[0][2]=50;
    graph1[1][2]=50;
    graph1[1][3]=50;
    graph1[1][4]=50;
    graph1[2][3]=99;
    graph1[3][4]=75;

    int** graph2 = _initGraph(4);
    graph2[0][1]=7;
    graph2[0][2]=10;
    graph2[1][2]=6;
    graph2[2][3]=6;

    if(countPaths(graph1,5,0,4) == 4
        && countPaths(graph1,5,1,4) == 3
        && countPaths(graph2,4,0,3) == 2
        && countPaths(graph2,4,2,0) == 0
       )
    {
        cout<<"Count paths:\tPass"<<endl;
    }else
    {
        cout<<"Count paths:\tFail"<<endl;
    }

    int** graph3 = _initGraph(8);
    graph3[0][5]=9;graph3[0][6]=9;graph3[0][7]=9;
    graph3[1][4]=9;graph3[1][6]=9;graph3[1][7]=9;
    graph3[2][4]=9;graph3[2][5]=9;graph3[2][7]=9;
    graph3[3][4]=9;graph3[3][5]=9;graph3[3][6]=9;
    graph3[4][1]=9;graph3[4][2]=9;graph3[4][3]=9;
    graph3[5][0]=9;graph3[5][2]=9;graph3[5][3]=9;
    graph3[6][0]=9;graph3[6][1]=9;graph3[6][3]=9;
    graph3[7][0]=9;graph3[7][1]=9;graph3[7][2]=9;

    vector<int> vertex_colors1 = getVertexColors(graph1, 5);
    vector<int> vertex_colors2 = getVertexColors(graph2, 4);
    vector<int> vertex_colors3 = getVertexColors(graph3, 8);

    if(_checkColors(graph1, 5, vertex_colors1)
        && _checkColors(graph2, 4, vertex_colors2)
        && _checkColors(graph3, 8, vertex_colors3)
       )
    {
        cout<<"Color graph:\tPass"<<endl;
    }else
    {
        cout<<"Color graph:\tFail"<<endl;
    }

    cout<<endl<<endl;

    cout<<"Color graph tests #1"<<endl;
    cout<<"Number of vertices: 5"<<endl;
    cout<<"Answer count: "<<_countColors(vertex_colors1)<<endl;
    cout<<"Optimal answer: 3"<<endl;

    cout<<endl;

    cout<<"Color graph tests #2"<<endl;
    cout<<"Number of vertices: 4"<<endl;
    cout<<"Answer count: "<<_countColors(vertex_colors2)<<endl;
    cout<<"Optimal answer: 3"<<endl;

    cout<<endl;

    cout<<"Color graph tests #3"<<endl;
    cout<<"Number of vertices: 8"<<endl;
    cout<<"Answer count: "<<_countColors(vertex_colors3)<<endl;
    cout<<"Optimal answer: 2"<<endl;


}
