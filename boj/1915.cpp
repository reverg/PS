#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    char board[1001][1001];
    for (int j = 1; j <= N; j++)
        for (int i = 1; i <= M; i++)
            cin >> board[j][i];

    int max_d = 0;
    int dp[1001][1001];
    for (int j = 1; j <= N; j++)
    {
        for (int i = 1; i <= M; i++)
        {
            if (board[j][i] == '1')
            {
                dp[j][i] = min({dp[j - 1][i - 1], dp[j - 1][i], dp[j][i - 1]}) + 1;
                max_d = max(max_d, dp[j][i]);
            }
            else
            {
                dp[j][i] = 0;
            }
        }
    }

    cout << max_d * max_d << '\n';
}