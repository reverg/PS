#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int dp[1001];
    dp[1] = 1, dp[2] = -1, dp[3] = 1, dp[4] = 1;
    for (int i = 5; i <= N; i++)
    {
        // 상근이가 돌 1, 3, 4개 중 1가지 가져가고 시작
        // 나머지에서 후순위가 이기는 방법 있으면 상근이 승리
        if (dp[i - 1] == -1 || dp[i - 3] == -1 || dp[i - 4] == -1)
            dp[i] = 1;
        else
            dp[i] = -1;
    }

    cout << (dp[N] == 1 ? "SK" : "CY") << '\n';
}