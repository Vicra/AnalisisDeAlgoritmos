#include "Test.h"
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

bool numberExists(vector<int> ordered_numbers, int x, int start, int ending)
{
    int mitad = (start + ending )/2;
    int b = ordered_numbers[mitad];

    if (b == x)
    {
        cout << x << " existe" << endl;
        return true;
    }
    else if(start == ending || start == ending+1)
    {
        cout << x << " no existe" << endl;
        return false;
    }
    else if(mitad > 0 && x < b)
    {
        return numberExists(ordered_numbers, x, start, mitad-1);
    }
    else if(mitad<ordered_numbers.size()-1 && x > b)
    {
        return numberExists(ordered_numbers, x, mitad+1, ending);
    }
}

bool numberExists(vector<int> ordered_numbers, int x)
{
    return numberExists(ordered_numbers, x, 0, ordered_numbers.size()-1);
}

bool existe(vector<int> ordered_numbers, int x)
{
    for(int i =0 ;i<ordered_numbers.size();i++)
    {
        if(ordered_numbers[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main ()
{
    //test();

    int arr1[] = { 1, 2, 3, 5, 6, 9, 12, 15, 16, 18,
                    20, 22, 23, 25, 26, 27, 29, 31, 32, 33,
                    54, 65, 67, 68, 69, 90, 105, 1000, 1005, 2356};
    std::vector<int> v1( arr1, arr1+30 );

    std::clock_t start;
    double duration;
    start = std::clock();

    if(numberExists(v1, 2357))
    {
        std::cout<<"existe: " <<'\n';
    }
    else
    {
        std::cout<<"no existe: " <<'\n';
    }

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout<<"duracion funcion A: "<< duration <<'\n';

    // ************************************************************************

    std::clock_t start_b;
    double duration_b;
    start_b = std::clock();

    if(existe(v1, 2357))
    {
        std::cout<<"existe: " <<'\n';
    }
    else
    {
        std::cout<<"no existe: " <<'\n';
    }

    duration_b = ( std::clock() - start_b ) / (double) CLOCKS_PER_SEC;
    std::cout<<"duracion funcion B: "<< duration_b <<'\n';

    return 0;
}
