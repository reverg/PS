#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int M;
vector<int> N, S;

void input()
{
    cin >> M;
    N.reserve(M);
    S.reserve(M);
    for (int i = 0; i < M; i++)
    {
        cin >> N[i] >> S[i];
    }
}

long long pow(long long n, long long pow)
{
    long long ret = 1;
    while (pow != 0)
    {
        if (pow & 1)
        {
            ret *= n;
            ret %= MOD;
        }
        pow >>= 1;
        n = (n * n) % MOD;
    }

    return ret;
}

long long sigma(long long mod)
{
    long long result = 0;

    for (int i = 0; i < M; i++)
    {
        result += (S[i] * pow(N[i], MOD - 2)) % MOD;
        result %= MOD;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    cout << sigma(MOD) << endl;
}