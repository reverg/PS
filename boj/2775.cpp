#include <iostream>
using namespace std;

int main()
{
    int human[15][15];
    int T;
    int k, n;
    cin>>T;

     for(int i=0; i<15; i++)
        {
            for(int j=1; j<15; j++)
            {
                if(i==0)
                    human[i][j]=j;
                else if(j==1)
                    human[i][j]=1;
                else
                    human[i][j]=human[i][j-1]+human[i-1][j];
            }
        }

    for(int t=0; t<T; t++)
    {
        cin>>k;
        cin>>n;

        cout<<human[k][n]<<endl;
    }

    return 0;
}