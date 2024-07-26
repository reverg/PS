#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N == 0)
    {
        cout << 0 << '\n'
             << 0 << '\n';
    }
    else
    {
        int abs_N = abs(N);
        int dp0 = 0, dp1 = 1;
        for (int i = 2; i <= abs_N; i++)
        {
            int dp2 = (dp0 + dp1) % 1000000000;
            dp0 = dp1;
            dp1 = dp2;
        }

        if (N > 0 || abs_N % 2 == 1)
        {
            cout << 1 << '\n'
                 << dp1 << '\n';
        }
        else
        {
            cout << -1 << '\n'
                 << dp1 << '\n';
        }
    }
}