#include <iostream>

using namespace std;

int num[501][501];

int triangle(int n)
{
    int max_path = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            num[i][j] += max(num[i - 1][j - 1], num[i - 1][j]);
    for (int i = 1; i <= n; i++)
    {
        if (num[n][i] > max_path)
            max_path = num[n][i];
    }
    return max_path;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> num[i][j];
    cout << triangle(n);
}