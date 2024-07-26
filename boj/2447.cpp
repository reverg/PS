#include <iostream>
using namespace std;

void byul(int i, int j, int n);

int main()
{
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            byul(i, j, N/3);
        }
        cout<<"\n";
    }

    return 0;
}

void byul(int i, int j, int n)
{
    if((i/n)%3==1&&(j/n)%3==1)
        cout<<" ";
    else if(n==1)
        cout<<"*";
    else
        byul(i, j, n/3);
}