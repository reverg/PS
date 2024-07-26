#include <iostream>
#include <unordered_map>

using namespace std;

const int MX = 100000 * 10 + 1;
const int ROOT = 1;
int unused = ROOT + 1;
int nxt[MX][26];
unordered_map<string, int> m;

inline int ctoi(char c)
{
    return c - 'a';
}

void insert(string &s)
{
    string ns = "";
    int cur = ROOT;
    for (auto c : s)
    {
        if (nxt[cur][ctoi(c)] == -1)
            nxt[cur][ctoi(c)] = unused++;
        cur = nxt[cur][ctoi(c)];
    }
}

string find(string &s)
{
    int cur = ROOT;
    string ns = "";
    for (auto c : s)
    {
        ns += c;
        if (nxt[cur][ctoi(c)] == -1)
            return ns;
        cur = nxt[cur][ctoi(c)];
    }
    if (m[s] > 1)
        ns += to_string(m[s]);
    return ns;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);

    while (N--)
    {
        string s;
        cin >> s;
        m[s]++;
        cout << find(s) << '\n';
        insert(s);
    }
}
