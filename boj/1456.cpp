#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ll A, B;
    cin >> A >> B;

    ll sqrt_b = ll(sqrt(B) + 1);
    bool prime[sqrt_b];
    fill(prime, prime + sqrt_b, true);
    for (ll i = 2; i <= sqrt_b; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= sqrt_b; j += i)
                prime[j] = false;
        }
    }

    ll ans = 0;
    for (ll i = 2; i <= sqrt_b; i++)
    {
        if (prime[i])
        {
            ll num = i;
            while (num <= B / i)
            {
                if (A <= num * i)
                    ans++;
                num *= i;
            }
        }
    }

    cout << ans << '\n';
}