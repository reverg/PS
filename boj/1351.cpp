#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

long long N, P, Q;
unordered_map<ll, ll> m;

long long solve(long long n)
{
    if (m.find(n) != m.end())
        return m[n];

    m[n] = solve(n / P) + solve(n / Q);
    return m[n];
}

int main()
{
    cin >> N >> P >> Q;

    if (N == 0)
        cout << 1 << '\n';
    else
    {
        m[0] = 1;
        cout << solve(N) << '\n';
    }
}