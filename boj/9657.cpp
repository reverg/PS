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
        if (dp[i - 1] == -1 || dp[i - 3] == -1 || dp[i - 4] == -1)
            dp[i] = 1;
        else
            dp[i] = -1;
    }

    cout << (dp[N] == 1 ? "SK" : "CY") << '\n';
}

/*
돌이 1, 3, 4개 있으면 상근이가 한번에 다 가져가서 게임을 이긴다.
나머지의 경우에는 창영이가 N-1, N-3, N-4개에서 이길 수 있는 방법이
있으면 상근이가 처음에 1/3/4개를 가져가고 N-1/N-3/N-4에 대한 창영이의
승리 전략을 사용해서 이길 수 있다. 창영이는 이외의 모든 경우에 이긴다.
*/