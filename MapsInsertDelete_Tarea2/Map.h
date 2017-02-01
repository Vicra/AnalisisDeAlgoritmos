#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Map
{
    string *array_key;
    int *array_value;
    int size;
    public:
        Map();
        void put(string key, int value);
        int get(string key);
        int getPos(string key);
        int funcionHash(string key, int rerun);
        bool exists(string key);
        void remove(string key);
};


#endif // MAP_H
