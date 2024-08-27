#include <iostream>

using namespace std;

int dp[100001];
int w[101], v[101];

int knapsack(int n, int k)
{
    for (int i = 0; i < n; i++)
        for (int j = k; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

    return dp[k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    cout << knapsack(n, k) << '\n';
}

/*
유명한 냅색 문제. 최대 무게에서 감소시키면서 갱신하면 1차원 배열로 풀 수 있다.
0에서부터 올라가면서 갱신하면 이번에 갱신한 dp[i]가 j > i인 dp[j]를 갱신하면서
반영 될 수 있으므로 중복을 포함하게 된다. 하지만 반대로 내려가면 갱신된 dp[j]가
dp[i]를 갱신할 때 반영되지 않으므로 최대 1번까지만 물건이 사용되게 된다.
중복해서 사용 가능한 문제는 #2293 참고.

2차원 배열을 사용하는 아래 코드가 좀 더 직관적일 수 있다. 올라가면서 갱신하되 물건을
차원별로 분리해서 같은 물건을 여러 번 쓰지 않게 하는 방식. 공간적으로 비효율적이다.

int knapsack(int n, int k)
{
    int dp[101][100001];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][k];
}
*/