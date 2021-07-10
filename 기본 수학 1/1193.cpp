#include <iostream>
using namespace std;

int main()
{
    int x;
    cin>>x;
    int cnt=0;

    for(int i=1; x>0; i++)
    {
        x-=i;
        cnt++;
    }

    if(cnt%2!=0)
        cout<<1-x<<"/"<<cnt+x;
    else
        cout<<cnt+x<<"/"<<1-x;
}