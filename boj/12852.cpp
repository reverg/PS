#include <iostream>

#define INF 2147483647

using namespace std;

int N;
int dp[1000001];
int before[1000001];

void GetInput()
{
    cin >> N;
}

void Initialize()
{
    dp[1] = 0;
    before[1] = 0;
    for (int i = 2; i <= N; i++)
        dp[i] = INF;
}

void PrintResult()
{
    cout << dp[N] << '\n';
    int cur = N;
    while (true)
    {
        cout << cur << ' ';
        if (before[cur] < 1)
            break;
        cur = before[cur];
    }
}

void DP()
{
    for (int i = 2; i <= N; i++)
    {
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            before[i] = i / 3;
        }
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            before[i] = i / 2;
        }
        if (dp[i] > dp[i - 1] + 1)
        {
            dp[i] = dp[i - 1] + 1;
            before[i] = i - 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    GetInput();

    Initialize();

    DP();

    PrintResult();
}