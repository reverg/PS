#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int K, L;
    cin >> K >> L;

    unordered_map<string, int> m;
    for (int i = 0; i < L; i++)
    {
        string s;
        cin >> s;
        m[s] = i;
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < min(K, (int)v.size()); i++)
        cout << v[i].first << '\n';
}