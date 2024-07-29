#include <iostream>

using namespace std;

int dp[101][100001];
int w[101], v[101];

int knapsack(int n, int k)
{
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    cout << knapsack(n, k) << '\n';
}

/*
유명한 knapsack 문제. 물건을 1개씩 더 넣어가면서 dp를 사용한다.
w[i] 무게 이상의 모든 수를 조작하므로 따로 이전 값을 받아오지 않는다.
bottom-up이 아니라 top-down을 쓰면 1차원 배열로 해결 가능하다.
bottom-up은 1차원 배열을 쓰면 같은 물건을 여러 번 쓰게 되어 틀린 풀이.
#2293처럼 같은 물건을 여러 번 쓰는 경우는 bottom-up 풀이가 가능하다.
*/