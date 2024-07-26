#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;
    
    for(int i=0; i<n; i++)
    {
        int c;
        cin>>c;
        if(c<x)
            cout<<c<<" ";
    }

    return 0;
}