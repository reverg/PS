#include <iostream>
using namespace std;

int main()
{
    int code[6]={0, };
    int sum=0;

    for (int i = 0; i < 5; i++)
    {
        code[i] = cin.get()-'0';
        cin.get();
    }

    
    for(int i=0; i<5; i++)
    {
        sum+=code[i]*code[i];
    }

    cout<<sum%10;
}