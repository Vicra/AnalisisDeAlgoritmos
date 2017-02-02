#include "Test.h"
#include <iostream>
#include <map>
#include "Map.h"
using namespace std;

int main ()
{
    //test();
    Map map;
    cout << "Puts" << endl;
    map.put("abc",10);
    map.put("bca",20);

    cout << endl << "Existen" << endl;
    cout << "abc: " << map.exists("abc") << endl;
    cout << "bca: " << map.exists("bca") << endl;

    cout << endl << "Remover" << endl;
    map.remove("bca");

    cout << endl << "Puts" << endl;
    map.put("cba",10);

    cout << endl << "Existen" << endl;
    cout << "abc: " << map.exists("abc") << endl;
    cout << "*: " << map.exists("*") << endl;
    cout << "pos " << map.getPos("cba") << endl;
    return 0;
}
