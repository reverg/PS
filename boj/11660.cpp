#include <iostream>

using namespace std;
int sum[1025][1025] = {
    0,
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> sum[i][j];
            sum[i][j] += sum[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum[i][j] += sum[i - 1][j];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << '\n';
    }
}