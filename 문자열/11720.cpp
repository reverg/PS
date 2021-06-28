#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char arr[n];
    cin>>arr;
    int sum=0;

    for(int i=0; i<n; i++)
        sum+=arr[i]-'0';

    cout<<sum;
    return 0;
}