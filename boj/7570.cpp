#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int dp[1000001] = {0};
    int x, ans = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> x;
        dp[x] = dp[x - 1] + 1;
        ans = max(ans, dp[x]);
    }

    cout << N - ans << '\n';
}

/*
가장 긴 연속되는 LIS 찾기. 맨 앞과 맨 뒤로 빼는 것만
가능하므로 연속해서 증가하지 않으면 다 앞뒤로 빼내야 한다.
LIS가 아닌 부분은 순서대로 앞/뒤로 빼면 정렬할 수 있다.
*/