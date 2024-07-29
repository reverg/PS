#include <iostream>

using namespace std;

int N;
int dp[31][31];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 30; i++)
    {
        for (int j = 1; j <= 30; j++)
        {
            if (i == j)
                dp[i][j] = 1;
            else if (i == 1)
                dp[i][j] = j;
            else
            {
                for (int k = j - 1; k >= i - 1; k--)
                    dp[i][j] += dp[i - 1][k];
            }
        }
    }

    cin >> N;
    for (int t = 0; t < N; t++)
    {
        int wsite, esite;
        cin >> wsite >> esite;
        cout << dp[wsite][esite] << endl;
    }
    return 0;
}

/*
DP로 풀이했으나 범위가 작아서 nCr 해도 충분하고 사실 그게 더 빠름.
j번째 사이트까지 i개 다리 짓기 = i-1개 다리 짓고 마지막 사이트 바로 옆에
다리 하나 더 짓기 = i-1번째...j-1번째 사이트까지 i-1개 다리 짓기 경우 합
*/