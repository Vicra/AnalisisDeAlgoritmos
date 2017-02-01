#include "Test.h"

void test()
{
    int arr1[] = { 1, 6, 9, 12, 54, 65, 90, 105, 1000, 2356};
    std::vector<int> v1( arr1, arr1+10 );

    int arr2[] = { 2, 4, 8, 10, 12, 14, 16, 18, 20, 22};
    std::vector<int> v2( arr2, arr2+10);

    int arr3[] = { 1, 6, 9, 12, 54, 65, 90, 105, 1000};
    std::vector<int> v3( arr3, arr3+9 );

    if(numberExists(v1, 90)
       && numberExists(v1, 105)
       && numberExists(v1, 2356)
       && !numberExists(v1, 3)
       && !numberExists(v1, 10000)
       && !numberExists(v1, 15)

       && numberExists(v2, 2)
       && numberExists(v2, 10)
       && numberExists(v2, 18)
       && !numberExists(v2, 5)
       && !numberExists(v2, 19)
       && !numberExists(v2, 23)

       && numberExists(v3, 1)
       && numberExists(v3, 1000)
       && numberExists(v3, 65)
       && !numberExists(v3, 2356)
       && !numberExists(v3, 10000)
       && !numberExists(v3, 15)
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
