#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int t, k, c;
    cin >> t;

    while (t--)
    {
        cin >> k >> c;

        // want y s.t. kx - cy = 1
        // use Extended Euclidean
        // r_(j-2) = r_(j-1) * q_j + r_j
        int r0 = k, r1 = c;
        long long s0 = 1, s1 = 0;
        long long t0 = 0, t1 = 1;
        int q, r2, s2, t2;

        if (c == 1)
        {
            if (k + 1 > 1e9)
                cout << "IMPOSSIBLE\n";
            else
                cout << k + 1 << '\n';
            continue;
        }

        while (true)
        {
            q = r0 / r1;
            r2 = r0 % r1;
            if (r2 == 0)
                break;

            s2 = s0 - q * s1;
            t2 = t0 - q * t1;

            r0 = r1, r1 = r2;
            s0 = s1, s1 = s2;
            t0 = t1, t1 = t2;
        }

        if (r1 != 1 || t1 > 1e9)
            cout << "IMPOSSIBLE\n";
        else if (t1 > 0)
            cout << t1 << '\n';
        else
            cout << k + t1 << '\n';
    }
}