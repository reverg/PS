#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    int len[100001] = {0};
    int cost[100001] = {0};
    for (int i = 1; i <= n - 1; i++)
        cin >> len[i];
    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    long long min_sum = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (cost[i] < cost[i + 1])
            cost[i + 1] = cost[i];
        min_sum += (long long)cost[i] * len[i];
    }

    cout << min_sum;
}