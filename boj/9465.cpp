#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int TC;
    cin >> TC;

    while (TC--)
    {
        int N;
        int sticker[100001][2] = {0};
        int dp[100001][2] = {0};
        cin >> N;
        for (int j = 0; j < 2; j++)
            for (int i = 1; i <= N; i++)
                cin >> sticker[i][j];

        dp[1][0] = sticker[1][0];
        dp[1][1] = sticker[1][1];
        for (int i = 2; i <= N; i++)
        {
            dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + sticker[i][0];
            dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + sticker[i][1];
        }
        cout << max(dp[N][0], dp[N][1]) << '\n';
    }
}

/*
dp[i][j] = i열까지 스티커가 있고, 마지막 열에서 j행 스티커를 가져갈 때 최대 점수
직전에 스티커를 가져간 행의 반대편 행에서 가져가면 마지막 열에서 무조건 스티커를
가져갈 수 있다.
*/