#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int tmp;
    int cnt=1;

    tmp=(n%10)*10+((n/10)+(n%10))%10;

    while(tmp!=n)
    {
        tmp=(tmp%10)*10+((tmp/10)+(tmp%10))%10;
        cnt++;
    }

    cout<<cnt;
    return 0;
}