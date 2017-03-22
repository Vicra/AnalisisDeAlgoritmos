#ifndef EVALUADOR_H
#define EVALUADOR_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <queue>
#include <list>
#include <set>

using namespace std;

void test();
int countPaths(int** DAG, int size, int origin, int destination);
vector<int> getVertexColors(int** graph, int size);

#endif // EVALUADOR_H
