#include <iostream>

using namespace std;

int dp[301];
int score[301];

int stepping(int n)
{
    if (n == 1)
        return score[1];
    else
    {
        dp[1] = score[1];
        dp[2] = score[1] + score[2];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = score[i] + max(score[i - 1] + dp[i - 3], dp[i - 2]);
        }
        return dp[n];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> score[i];
    cout << stepping(n);
}

/*
3칸 연속 밟으면 안되니까 3칸 전->1칸 전->현재 아니면 2칸 전->현재만 가능
아니면 직전에 1칸을 뛰었는지 2칸을 뛰었는지로 나눠 dp[N][2] 만들어도 됨
*/