#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int flipped_a, flipped_b;

    cin>>a>>b;

    flipped_a=a+(a%10-a/100)*99;
    flipped_b=b+(b%10-b/100)*99;

    if(flipped_a>flipped_b)
        cout<<flipped_a;
    else   
        cout<<flipped_b;

    return 0;
}