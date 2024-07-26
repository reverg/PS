#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    int result=a*b*c;

    int digit[10]={0, };
    
    while(result>0)
    {
        digit[result%10]++;
        result/=10;
    }

    for(int i=0; i<10; i++)
        cout<<digit[i]<<endl;

    return 0;
}