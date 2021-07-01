#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int result=1;
    
    for(int i=n; i>=n-k+1; i--)
        result*=i;
    if(k==0)
        result=1;
    else
    {
        for(int i=1; i<=k; i++)
            result/=i;
    }
    
    cout<<result;
    return 0;
}