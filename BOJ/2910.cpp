#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> order;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return order[a.second] < order[b.second];
    }
    else
    {
        return a.first > b.first;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;
    cin >> N >> C;

    map<int, int> m;
    vector<pair<int, int>> v;
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        m[num]++;
        if (order[num] == 0)
        {
            order[num] = i + 1;
        }
    }

    for (auto i : m)
    {
        v.emplace_back(i.second, i.first);
    }

    sort(v.begin(), v.end(), compare);

    for (auto i : v)
    {
        for (int j = 0; j < i.first; j++)
        {
            cout << i.second << " ";
        }
    }
}