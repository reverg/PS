#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long dp[101];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= 100; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
}

/*
그림만 보면 n=5부터 될 것 같지만 n=4도 동일한 숫자로 가능하다.
직관적으로는 그냥 dp[4]=2까지 직접 넣어주는게 편하긴 할 듯.
*/