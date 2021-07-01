#include <iostream>
#include <string>
using namespace std;

int main()
{
    int p;
    cin>>p;

    for(int i=0; i<p; i++)
    {
        int n;
        cin>>n;
        string p;
        cin>>p;

        for(int j=0; j<p.length(); j++)
        {           
            for(int k=0; k<n; k++)
                cout<<p[j];
        }
        cout<<endl;
    }

    return 0;
}