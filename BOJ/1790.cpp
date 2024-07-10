#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;

    int nl = 1;
    long long ns = 1;
    while (K - (9 * nl * ns) > 0)
    {
        K -= 9 * nl * ns;
        nl++;
        ns *= 10;
    }

    long long num = ns + (K - 1) / nl;
    if (num > N)
        cout << -1 << '\n';
    else
    {
        int left = (K - 1) % nl;
        int ans = (long long)(num / pow(10, nl - left - 1)) % 10;
        cout << ans << '\n';
    }
}