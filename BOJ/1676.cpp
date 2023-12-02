#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int number_of_five = 0;

    for(int i=5; i<=n; i*=5)
    {
        number_of_five+=n/i;
    }
   
   cout<<number_of_five;
    return 0;
}