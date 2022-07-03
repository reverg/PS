#include <iostream>
using namespace std;

int main()
{
    long t;
    int a, b;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>t;

    for(long i=0; i<t-1; i++)
    {
        cin>>a>>b;
        cout<<a+b<<"\n";
    }

    cin>>a>>b;
    cout<<a+b;

    return 0;
}