#include <iostream>

using namespace std;

const int MOD = 1000000000;
long long stair[101][10];

int count_stair(int n)
{
    long long sum = 0;
    stair[1][0] = 0;
    for (int i = 1; i <= 9; i++)
        stair[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        stair[i][0] = stair[i - 1][1];
        stair[i][9] = stair[i - 1][8];
        for (int j = 1; j <= 8; j++)
            stair[i][j] = (stair[i - 1][j - 1] + stair[i - 1][j + 1]) % MOD;
    }
    for (int i = 0; i <= 9; i++)
        sum += stair[n][i];
    return sum % MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << count_stair(n);
}