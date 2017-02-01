#include "Map.h"

int Map::funcionHash(string key, int rerun)
{
    int suma=0;
    for(int i=0;i<key.size();i++)
    {
        suma+=key[i];
    }
    return suma+rerun;
}

Map::Map()
{
    int size = 10000;
    array_key = new string[size];
    array_value = new int[size];

    for(int i=0;i<size;i++)
        array_key[i]="";
}

void Map::put(string key, int value)
{
    int rerun = 0;
    int pos;
    do
    {
        pos = funcionHash(key,rerun);
        rerun++;
    }while(array_key[pos]!="");

    cout << "llave: " << key << " pos : " << pos <<endl;
    array_key[pos]=key;
    array_value[pos]=value;
}

int Map::get(string key)
{
    int rerun = 0;
    int pos;
    do
    {
        pos = funcionHash(key,rerun);
        rerun++;

    }while(array_key[pos]!=key && array_key[pos]!= "");

    if(array_key[pos] == "")
    {
        return-1;
    }
    return array_value[pos];
}

int Map::getPos(string key)
{
    int rerun = 0;
    int pos;
    do
    {
        pos = funcionHash(key,rerun);
        rerun++;

    }while(array_key[pos]!=key && array_key[pos]!= "");

    if(array_key[pos] == "")
    {
        return-1;
    }
    return pos;
}

bool Map::exists(string key)
{
    return get(key) > 0 ? true : false;
}

void Map::remove(string key)
{
    int pos = getPos(key);
    cout<<"Posicion: "<< key << " es " << pos << endl;
    if(pos > 0)
    {
        array_key[pos] = "";
    }
}
