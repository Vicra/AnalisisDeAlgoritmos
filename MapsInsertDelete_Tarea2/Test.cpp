#include "Test.h"
#include "Map.h"

void test()
{
    Map map;
    map.put("A",10);
    map.put("B",20);
    map.put("C",30);
    map.put("arroz",100);
    map.put("zorra",200);
    map.put("abc",1);
    map.put("acb",2);
    map.put("bac",3);
    map.put("bca",4);

    map.remove("A");
    map.remove("zorra");
    map.remove("bac");

    map.put("cab",5);

    if(map.get("B")==20
       && map.get("C")==30
       && map.get("arroz")==100
       && map.get("abc")==1
       && map.get("acb")==2
       && map.get("bca")==4

       && !map.exists("A")
       && map.exists("B")
       && map.exists("C")

       && map.exists("arroz")
       && !map.exists("zorra")
       && map.exists("abc")
       && map.exists("acb")
       && !map.exists("bac")
       && map.exists("bca")
       && map.exists("cab")
       )
   {
       cout<<"Pass"<<endl;
   }else
   {
       cout<<"Fail"<<endl;
   }

}
