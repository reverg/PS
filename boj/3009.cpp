#include <iostream>
using namespace std;

int main()
{
    int xpos[3], ypos[3];
    for(int i=0; i<3; i++)
        cin>>xpos[i]>>ypos[i];

    if(xpos[0]==xpos[1])
        cout<<xpos[2];
    else if(xpos[0]==xpos[2])
        cout<<xpos[1];
    else
        cout<<xpos[0];

    if(ypos[0]==ypos[1])
        cout<<" "<<ypos[2];
    else if(ypos[0]==ypos[2])
        cout<<" "<<ypos[1];
    else
        cout<<" "<<ypos[0];

    return 0;
}