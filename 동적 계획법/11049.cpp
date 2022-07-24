#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int mul[501][501] = {0};
vector<pair<int, int>> v;

int mulMin(int n)
{
    for (int j = 1; j <= n - 1; j++)
    {
        for (int i = 1; i + j <= n; i++)
        {
            mul[i][i + j] = INT32_MAX;
            for (int mid = i; mid < i + j; mid++)
            {
                int cost = mul[i][mid] + mul[mid + 1][i + j];
                cost += v[i].first * v[mid].second * v[i + j].second;
                mul[i][i + j] = min(mul[i][i + j], cost);
            }
        }
    }
    return mul[1][n];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, r, c;
    cin >> n;

    v.emplace_back(make_pair(0, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> r >> c;
        v.emplace_back(make_pair(r, c));
    }
    cout << mulMin(n);
}