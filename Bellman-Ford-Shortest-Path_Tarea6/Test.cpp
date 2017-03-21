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

bool compare(int* a, int* b, int size)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}


void test()
{
    int** g1 = _initGraph(5);
    g1[0][1]=2;
    g1[0][2]=6;
    g1[0][3]=7;

    g1[1][3]=3;
    g1[1][4]=6;

    g1[2][4]=1;

    g1[3][4]=5;

    static const int r1[] = {NULL,0,0,1,2};

    int** g2 = _initGraph(5);
    g2[0][1]=1;
    g2[0][2]=10;

    g2[1][3]=2;

    g2[2][3]=-10;

    g2[3][4]=3;

    static const int r2[] = {NULL,0,0,2,3};


    int* a1 = getShortestPath(g1, 5, 0);
    int* a2 = getShortestPath(g2, 5, 0);

    if(a1 && a2
       && compare(a1, (int*)r1, 5)
       && compare(a2, (int*)r2, 5)
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
