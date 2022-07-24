#include <iostream>
#include <climits>

using namespace std;

long long cost[501][501] = {0};
long long sum[501] = {0};

long long mergeChapter(int k)
{
    for (int d = 1; d < k; d++)
    {
        for (int i = 1; i <= k - d; i++)
        {
            cost[i][i + d] = LLONG_MAX;
            for (int j = i; j < i + d; j++)
            {
                long long new_cost = cost[i][j] + cost[j + 1][i + d] + sum[i + d] - sum[i - 1];
                cost[i][i + d] = min(cost[i][i + d], new_cost);
            }
        }
    }

    return cost[1][k];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int size;
            cin >> size;
            sum[j] = sum[j - 1] + size;
        }
        cout << mergeChapter(k) << '\n';
    }
}