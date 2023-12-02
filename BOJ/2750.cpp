#include <iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
        cin.get();
    }

    for(int i=0; i<N; i++)
    {
        for(int j=i; j<N; j++)
        {
            if(arr[i]>arr[j])
            {
                int tmp;
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }

    for(int i=0; i<N; i++)
        cout<<arr[i]<<'\n';
    
    return 0;
}