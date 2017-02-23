#include "Test.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> swap(vector<int> vec, int pos0, int pos1) {
    int aux = vec[pos0];
    vec[pos0] = vec[pos1];
    vec[pos1] = aux;
    return vec;
}

vector<int> replace(vector<int> min_heap, int replaced_value, int replacement) {
    int actual = 0;
    int padre = 0;

    int padreIndex = 0;
    int leftIndex = 0;
    int rightIndex = 0;

    int i;
    for(i = 0; i < min_heap.size(); i++)
    {
        if(min_heap[i] == replaced_value)
        {
            min_heap[i] = replacement;
            break;
        }

    }

    while(i > 0 && i <= min_heap.size())
    {
        leftIndex   = (i*2) + 1;
        rightIndex  = (i*2) + 2;
        padreIndex = (i%2 == 0) ? (i-2)/2 : (i-1)/2;

        padre = min_heap[padreIndex];
        actual = min_heap[i];

        if(padre > actual) {
            min_heap = swap(min_heap, padreIndex, i);
            i = padreIndex;
        } else if((leftIndex < min_heap.size() && actual > min_heap[leftIndex]) || (rightIndex < min_heap.size() && actual > min_heap[rightIndex])) {

            if( min_heap[leftIndex] < min_heap[rightIndex]) {
                min_heap = swap(min_heap, leftIndex, i);
                i = leftIndex;
            } else {
                min_heap = swap(min_heap, rightIndex, i);
                i = rightIndex;
            }
        } else {
            break;
        }
    }

    return min_heap;
}

int main ()
{
    test();
    return 0;
}
