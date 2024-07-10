#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> v[i];

    int ans = 0;
    vector<int> dp(N + 1);
    for (int i = 1; i <= N; i++)
    {
        int max_n = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                max_n = max(max_n, dp[j] + 1);
            }
            dp[i] = max_n;
            ans = max(ans, dp[i]);
        }
    }

    cout << N - ans << '\n';
}