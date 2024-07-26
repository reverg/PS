#include <iostream>

using namespace std;

long long remain(long long a, long long b, long long c)
{
    if (b == 1)
        return a % c;

    if (b % 2 == 0)
        return (remain(a, b / 2, c) * remain(a, b / 2, c) % c);
    else
        return ((remain(a, b / 2, c) * remain(a, b / 2, c) % c) * (a % c)) % c;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;

    cout << remain(a, b, c);
}