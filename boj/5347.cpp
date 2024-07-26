#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);

    while (b != 0)
    {
        a = a % b;
        swap(a, b);
    }
    return a;
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int a, b;
        cin >> a >> b;
        cout << (long long)a / gcd(a, b) * b << '\n';
    }
}