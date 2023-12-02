#include <iostream>
using namespace std;

int main()
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

    cout<<b<<endl<<mul/b;

    return 0;
}