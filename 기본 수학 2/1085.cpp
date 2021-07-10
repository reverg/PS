#include <iostream>
using namespace std;

int main()
{
    int x, y, w, h;
    int arr[4];
    int min=1000;

    cin>>x>>y>>w>>h;
    
    arr[0]=x;
    arr[1]=y;
    arr[2]=w-x;
    arr[3]=h-y;
    
    for(int i=0; i<4; i++)
    {
        if(arr[i]<min)
            min=arr[i];
    }

    cout<<min;
    return 0;
}