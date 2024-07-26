#include <iostream>
using namespace std;

int main()
{
    int number=0;
    cin>>number;
    int arr[number];
    int max=0;
    int min=1000000;

    for(int i=0; i<number; i++)
    {
        cin>>arr[i];

        if(max<arr[i])
            max=arr[i];

        if(min>arr[i])
            min=arr[i];
    }
    cout<<max*min;
    return 0;
}