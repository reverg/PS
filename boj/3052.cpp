#include <iostream>
using namespace std;

int main()
{
    int mod[42]={0, };
    int cnt=0;

    for(int i=0; i<10; i++)
    {
        int num;
        cin>>num;
        if(mod[num%42]==0)
        {
            cnt++;
            mod[num%42]=1;
        }
    }

    cout<<cnt;
    
    return 0;
}