#include <iostream>
#include <algorithm>

using namespace std;

int make_one(int n)
{
    int dp[1000001];
    dp[0] = dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int min_cost = dp[i - 1];
        if (i % 6 == 0)
            min_cost = min({dp[i / 3], dp[i / 2], dp[i - 1]});
        else if (i % 3 == 0)
            min_cost = min(dp[i / 3], dp[i - 1]);
        else if (i % 2 == 0)
            min_cost = min(dp[i / 2], dp[i - 1]);

        dp[i] = min_cost + 1;
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << make_one(n);
}

/*
n이 작으면 BFS로도 가능하다.
*/