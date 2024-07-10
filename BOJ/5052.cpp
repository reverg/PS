#include <iostream>

using namespace std;

const int MX = 10000 * 10 + 1;
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MX][10];
int mark[MX];

int ctoi(char c)
{
    return c - '0';
}

bool insert(string &s)
{
    int cur = ROOT;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (nxt[cur][ctoi(c)] == -1)
            nxt[cur][ctoi(c)] = unused++;
        cur = nxt[cur][ctoi(c)];

        if (mark[cur])
            return false;
    }
    if (cur != unused - 1)
        return false;

    mark[cur] = true;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        fill(mark, mark + MX, 0);
        for (int i = 0; i < MX; i++)
            fill(nxt[i], nxt[i] + 10, -1);
        unused = ROOT + 1;

        int N;
        cin >> N;

        bool isvalid = true;
        while (N--)
        {
            string s;
            cin >> s;
            if (!insert(s))
                isvalid = false;
        }
        if (isvalid)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

/*
Trie.
*/