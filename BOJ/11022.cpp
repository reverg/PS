#include <iostream>
using namespace std;

int main()
{
    int n, a, b;
    cin>>n;

    for(int i=0; i<n-1; i++)
    {
        cin>>a>>b;
        cout<<"Case #"<<i+1<<": "<<a<<" + "<<b<<" = "<<a+b<<endl;
    }
 
    cin>>a>>b;
    cout<<"Case #"<<n<<": "<<a<<" + "<<b<<" = "<<a+b<<endl;
    
    return 0;
}