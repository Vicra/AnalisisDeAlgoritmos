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

    for(int i=0; i<min_heap.size(); i++){
        cout << "valor en posicion " << i << ": " << min_heap[i] << endl;
    }

    cout << "----replaced_value: " << replaced_value << endl;
    cout << "----replacement: " << replacement << endl <<endl;
    int actual = 0;
    int super = 0;

    int superPosition = 0;
    int leftPosition = 0;
    int rightPosition = 0;

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
        leftPosition   = (i*2) + 1;

        rightPosition  = (i*2) + 2;

        superPosition = (i%2 == 0) ? (i-2)/2 : (i-1)/2;
        cout << "super index: " << superPosition << ", valor: " << min_heap[superPosition] << endl;
        cout << "left index: " << leftPosition << ", valor: " << min_heap[leftPosition] <<endl;
        cout << "right index: " << rightPosition << ", valor: " << min_heap[rightPosition] << endl << endl;


        super = min_heap[superPosition];
        actual = min_heap[i];
        cout << "super: " << super << " index: " << superPosition << endl;
        cout << "actual: " << actual << endl <<endl;

        if(super > actual) {
            min_heap = swap(min_heap, superPosition, i);
            i = superPosition;
            cout << "super es mayor que actual" << endl;
            cout << "swap, posicion padre: " << superPosition << ", i :" << i << endl << endl;
        } else if((leftPosition < min_heap.size() && actual > min_heap[leftPosition])
                  || (rightPosition < min_heap.size() && actual > min_heap[rightPosition])) {

            if( min_heap[leftPosition] < min_heap[rightPosition]) {
                min_heap = swap(min_heap, leftPosition, i);
                i = leftPosition;
                cout << "left es menor que right" << endl;
                cout << "swap, posicion left position: " << leftPosition << ", i :" << i << endl << endl;
            } else {
                min_heap = swap(min_heap, rightPosition, i);
                i = rightPosition;
                cout << "right es menor que left" << endl;
                cout << "swap, posicion right position: " << rightPosition << ", i :" << i << endl << endl;
            }
        } else {
            break;
        }
    }
    cout << "valores" <<endl;
    for(int i=0; i<min_heap.size(); i++){
        cout << "valor en posicion " << i << ": " << min_heap[i] << endl;
    }
    cout << "fin valores" <<endl;
    return min_heap;
}

int main ()
{
    test();
    return 0;
}
