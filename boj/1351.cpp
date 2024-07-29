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

/*
0 <= N <= 10^12라 배열을 만들기는 너무 크다.
set을 사용해서 top-down으로 처리해주면 된다.
10^12 ~= 2^40이라 recursion depth는 무리가 없는 수준.
*/