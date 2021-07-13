#include <iostream>
using namespace std;

void hanoi(int n, int from, int via, int to)
{
    if(n==1)
        cout<<from<<" "<<to<<"\n";
    else
    {
        hanoi(n-1, from, to, via);
        cout<<from<<" "<<to<<"\n";
        hanoi(n-1, via, from, to);
    }
}        

int main()
{
    int N;
    cin>>N;

    int K=0;
    for(int i=0; i<N; i++)
    {
        K=2*K+1;
    }

    cout<<K<<"\n";
    hanoi(N, 1, 2, 3);
    return 0;
}