#include <iostream>
#include <climits>

using namespace std;

long long cost[5001][5001];
long long min_mid[5001][5001];
long long sum[5001];

long long mergeChapter(int k)
{
    for (int i = 1; i <= k; i++)
        min_mid[i - 1][i] = i;

    for (int d = 2; d <= k; d++)
    {
        for (int i = 0; i + d <= k; i++)
        {
            int j = i + d;
            cost[i][j] = LLONG_MAX;
            for (int mid = min_mid[i][j - 1]; mid <= min_mid[i + 1][j]; mid++)
            {
                long long new_cost = cost[i][mid] + cost[mid][j] + sum[j] - sum[i];
                if (cost[i][j] > new_cost)
                {
                    cost[i][j] = new_cost;
                    min_mid[i][j] = mid;
                }
            }
        }
    }

    return cost[0][k];
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