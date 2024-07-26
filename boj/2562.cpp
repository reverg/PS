#include <iostream>
using namespace std;

int main()
{
    int arr[9];
    int max=-1;
    int maxidx=-1;

    for(int i=0; i<9; i++)
    {
        cin>>arr[i];
        if(arr[i]>max)
        {
            max=arr[i];
            maxidx=i+1;
        }
    }

    cout<<max<<endl<<maxidx;
    return 0;
}