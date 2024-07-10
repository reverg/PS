// reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1F/solutions/16906.cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MX = 1000 + 1;
const int ROOT = 1;
int unused = ROOT + 1;
int nxt[MX][2];
bool chk[MX] = {false};
vector<pair<int, int>> v;
map<int, string> m;

inline int ctoi(char c)
{
    return c - '0';
}

void insert(string &s)
{
    int cur = ROOT;
    for (char c : s)
    {
        if (nxt[cur][ctoi(c)] == -1)
            nxt[cur][ctoi(c)] = unused++;
        cur = nxt[cur][ctoi(c)];
    }
    chk[cur] = true;
}

bool find(string s)
{
    int cur = ROOT;
    for (auto c : s)
    {
        if (nxt[cur][ctoi(c)] == -1)
            return false;
        cur = nxt[cur][ctoi(c)];
    }
    return chk[cur];
}

pair<string, bool> dfs(int l, string s)
{
    pair<string, bool> res;
    if (s.size() == l)
    {
        insert(s);
        return {s, true};
    }

    string s0 = s + '0';
    if (!find(s0))
        res = dfs(l, s0);
    if (res.second)
        return res;

    string s1 = s + '1';
    if (!find(s1))
        res = dfs(l, s1);
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 2, -1);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int l;
        cin >> l;
        v.push_back({l, i});
    }

    sort(v.begin(), v.end());

    bool success = true;
    for (int i = 0; i < N; i++)
    {
        auto [len, idx] = v[i];
        auto [newWord, inserted] = dfs(len, "");

        if (!inserted)
        {
            success = false;
            break;
        }

        m[idx] = newWord;
    }

    if (success)
    {
        cout << 1 << '\n';
        for (int i = 0; i < N; i++)
            cout << m[i] << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

/*
Trie에 새로운 단어를 만들어 넣는 문제.
백트래킹으로 짧은 단어부터 순차적으로 만들어나가는데, 생성 중인 문자열이
이미 만들어진 단어면 해당 문자열은 사용할 수 없다.
*/