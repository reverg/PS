#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

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
                dp[j][i] = 0;
        }
    }

    cout << max_d * max_d << '\n';
}

/*
dp[j][i] = (j, i)를 우측 하단 꼭지점으로 갖는 최대 정사각형 변 길이
왼쪽, 왼쪽위, 위쪽 칸을 우하단으로 하는 정사각형과 칸을 공유하게 되어
27행의 점화식이 나온다. 직접 그려보는게 이해하기 쉽다.
*/