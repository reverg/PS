#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int r;
    cin >> r;
    cout<<fixed;
    cout.precision(6);
    cout << (long double)r * r * M_PI << endl
         << r * r * 2;

    return 0;
}