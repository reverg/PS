#include <iostream>
using namespace std;

int main()
{
    int p, n;
    cin>>p;

    for(int i=0; i<p; i++)
    {
        cin>>n;
        char arr[21];

        cin.get();

        for(int j=0; j<21; j++)
        {   
            arr[j]=cin.get();
            if(arr[j]=='\n')
                break;
            
            for(int k=0; k<n; k++)
                cout<<arr[j];
        }
        cout<<endl;
    }

    return 0;
}