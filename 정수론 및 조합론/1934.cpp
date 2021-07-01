#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    for(int i=0; i<t; i++)
    {
    int a, b;
    cin>>a>>b;
    int mul=a*b;

    if(a<b)
    {
        int tmp=b;
        b=a;
        a=tmp;
    }

    while(a%b!=0)
    {
        a=a%b;
        int tmp=b;
        b=a;
        a=tmp;
    }

    cout<<mul/b<<endl;
    }

    return 0;
}