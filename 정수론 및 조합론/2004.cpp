#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int num5 = 0;
    int num2 = 0;

    for (long long i = 5; i <= n; i *= 5)
    {
        num5 += n / i;
    }

    for (long long i = 5; i <= k; i *= 5)
    {
        num5 -= k / i;
    }

    for (long long i = 5; i <= n - k; i *= 5)
    {
        num5 -= (n - k) / i;
    }

    for (long long i = 2; i <= n; i *= 2)
    {
        num2 += n / i;
    }

    for (long long i = 2; i <= k; i *= 2)
    {
        num2 -= k / i;
    }

    for (long long i = 2; i <= n - k; i *= 2)
    {
        num2 -= (n - k) / i;
    }

    if(num5>num2)
        cout<<num2;
    else
        cout<<num5;
    //cout << (num5 > num2 ? num2 : num5);
    return 0;
}