#include <iostream>
using namespace std;

void hansu_check(int n)
{
    int cnt=0;

    for(int i=1; i<=n; i++)
    {
        int tmp=i;
        int digits[3]={0, };
        
        for(int j=0; j<3; j++)
        {
            digits[j]=tmp%10;
            tmp/=10;
        }

        if((digits[1]-digits[0])==digits[2]-digits[1])
            cnt++;
        else if(digits[2]==0||(digits[2]==0&&digits[1]==0))
            cnt++;
    }
    
    if(n==1000)
        cnt--;

    cout<<cnt;
}

int main()
{
    int n;
    cin>>n;
    hansu_check(n);
    return 0;
}