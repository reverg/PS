#include <iostream>
using namespace std;

int main()
{
    int a;
    cin>>a;

    for(int i=1; i<9; i++)
    {
        cout<<a<<" * "<<i<<" = "<<a*i<<endl;
    }
 
    cout<<a<<" * "<<9<<" = "<<a*9;
    
    return 0;
}