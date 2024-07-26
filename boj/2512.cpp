#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> cost;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        cost.push_back(tmp);
    }
    sort(cost.begin(), cost.end());

    int M;
    cin >> M;

    int total_budget = 0;
    int max_budget = 0;
    bool sufficient = true;
    for (int i = 0; i < N; i++)
    {
        int avg_cost = (M - total_budget) / (N - i);
        if (cost[i] < avg_cost)
        {
            total_budget += cost[i];
        }
        else
        {
            max_budget = avg_cost;
            sufficient = false;
            break;
        }
    }

    cout << (sufficient ? cost[N - 1] : max_budget) << '\n';
}