#include <iostream>

using namespace std;
#define PRIME 1000000007

long long fact_part(int k, int n)
{
    long long val = 1;

    for (int i = k; i <= n; i++)
    {
        val *= i;
        val %= PRIME;
    }

    return val;
}

long long pow(int base, int exp)
{
    if (exp == 1)
        return base % PRIME;

    long long pow_half = pow(base, exp / 2) % PRIME;

    if (exp % 2 == 0)
        return (pow_half * pow_half) % PRIME;
    else
        return (((pow_half * pow_half) % PRIME) * base) % PRIME;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    // nCk = n! / (n-k)!k!
    // = n(n-1)...(n-k+1) / k!
    // = n(n-1)...(n-k+1)*(k!)^(p-2) (mod p)

    long long n_fact = fact_part(n - k + 1, n);
    long long k_fact = fact_part(1, k);

    cout << (n_fact * pow(k_fact, PRIME - 2)) % PRIME;
}