#include <iostream>
#include <vector>

using namespace std;

int N;
int room[16][16];

void input()
{
    cin >> N;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> room[j][i];
        }
    }
}

int movePipe()
{
    int dp[N][N][3];
    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(dp[0][0][0]), 0);
    for (int i = 1; i < N; i++)
    {
        if (room[0][i] == 1)
            break;

        dp[0][i][0] = 1;
    }

    for (int j = 1; j < N; j++)
    {
        for (int i = 2; i < N; i++)
        {
            if (room[j][i] != 1)
            {
                dp[j][i][0] = dp[j][i - 1][0] + dp[j][i - 1][2];
                dp[j][i][1] = dp[j - 1][i][1] + dp[j - 1][i][2];
                if (room[j - 1][i] != 1 && room[j][i - 1] != 1)
                {
                    dp[j][i][2] = dp[j - 1][i - 1][0] + dp[j - 1][i - 1][1] + dp[j - 1][i - 1][2];
                }
            }
        }
    }

    return dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    cout << movePipe() << endl;
}