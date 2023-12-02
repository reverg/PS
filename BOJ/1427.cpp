#include <iostream>
using namespace std;

int main()
{
    string N;
    cin>>N;
    int digit[10]={0, };
    for(int i=0; i<N.length(); i++)
    {
        digit[N[i]-'0']++;
    }

    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < digit[i]; j++)
            cout << i;
    }

    return 0;
}