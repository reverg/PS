#include <iostream>

using namespace std;

int sum = 0;
int dp[10001];
int m[101], c[101];

int memory(int N, int M)
{
    for (int i = 1; i <= N; i++)
        for (int j = sum; j >= c[i]; j--)
            dp[j] = max(dp[j], dp[j - c[i]] + m[i]);

    for (int i = 0; i <= sum; i++)
        if (dp[i] >= M)
            return i;

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> m[i];

    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
        sum += c[i];
    }

    cout << memory(N, M) << '\n';
}

/*
일반적인 냅색처럼 메모리를 기준으로 잡으면 배열 크기가 감당이 안된다.
비용 관점에서 계산해두고 조건을 만족하는 가장 작은 메모리를 확인해야
제한을 넘지 않는다. top-down으로 하면 1차원 배열로 깔끔하게 풀린다.
*/