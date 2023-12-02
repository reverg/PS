#include <iostream>

using namespace std;

int rgb[1001][3];
int cost[1001][3];

int coloring(int n)
{
    int min_cost;

    for (int i = 1; i <= n; i++)
    {
        cost[i][0] = rgb[i][0] + min(cost[i - 1][1], cost[i - 1][2]);
        cost[i][1] = rgb[i][1] + min(cost[i - 1][0], cost[i - 1][2]);
        cost[i][2] = rgb[i][2] + min(cost[i - 1][0], cost[i - 1][1]);

        min_cost = min(cost[i][0], cost[i][1]);
        min_cost = min(min_cost, cost[i][2]);
    }
    return min_cost;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    cout << coloring(n);
}