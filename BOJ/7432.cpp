#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

const int MX = 500 * 80 + 5;
const int ROOT = 1;
int unused = ROOT + 1;
unordered_map<string, int> nxt[MX];
int depth[MX];
string name[MX];

void insert(vector<string> &route)
{
    int cv = ROOT;
    for (string k : route)
    {
        int nv = nxt[cv][k];
        if (nv == 0)
            nv = nxt[cv][k] = unused++;
        depth[nv] = depth[cv] + 1;
        name[nv] = k;
        cv = nv;
    }
}

void dfs(int start)
{
    if (start != ROOT)
    {
        for (int i = 0; i < depth[start]; i++)
            cout << ' ';
        cout << name[start] << '\n';
    }

    vector<pair<string, int>> v(nxt[start].begin(), nxt[start].end());
    sort(v.begin(), v.end());
    for (auto ns : v)
        dfs(ns.second);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    depth[ROOT] = -1;

    while (N--)
    {
        string s;
        cin >> s;

        string cur = "";
        vector<string> route; // slash로 끊은 부분들 저장
        for (auto c : s)
        {
            if (c == '\\')
            {
                route.push_back(cur);
                cur = "";
            }
            else
            {
                cur += c;
            }
        }

        route.push_back(cur);
        insert(route);
    }

    dfs(ROOT);
}

/*
slash 단위로 끊어서 Trie.
*/