#include <iostream>
using namespace std;

int main()
{
    int room;
    cin>>room;
    room-=1;

    int cnt=1;
    int side=0;

    while(room>0)
    {
        side++;
        room-=side*6;
        
        cnt++;
    }

    cout<<cnt;
    
    return 0;
}