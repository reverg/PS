#include <iostream>
using namespace std;

int gcd(int a, int b);
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    for(int i=1; i<n; i++)
    {   
        int div=gcd(arr[0], arr[i]);
        cout<<arr[0]/div<<"/"<<arr[i]/div<<endl;
    }

    return 0;
}

int gcd(int a, int b)
{
    if(a<b)
    {
        int tmp=b;
        b=a;
        a=tmp;
    }
    
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}