#include <iostream>

using namespace std;

int sum = 0;
int dp[101][10001];
int m[101], c[101];

int memory(int N, int M)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= c[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + m[i]);

            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    for (int i = 0; i <= sum; i++)
    {
        if (dp[N][i] >= M)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> m[i];

    for (int i = 1; i <= N; i++)

    {
        cin >> c[i];
        sum += c[i];
    }

    cout << memory(N, M);
}