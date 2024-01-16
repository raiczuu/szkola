#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
         int a[12];

    srand( time( NULL ) );
    for(int i=0; i<12; i++)
    {
        a[i]=rand()%100+1;
    }
    for (int i=0; i<12; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}