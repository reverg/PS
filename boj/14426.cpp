// reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1F/solutions/14426.cpp
#include <iostream>

using namespace std;

const int MAX = 10000 * 500 + 5;
const int ROOT = 1;

int unused = ROOT + 1;
int nxt[MAX][26];

int ctoi(char c)
{
    return c - 'a';
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
}

bool check(string &s)
{
    int cur = ROOT;
    for (char c : s)
    {
        if (nxt[cur][ctoi(c)] == -1)
            return 0;
        cur = nxt[cur][ctoi(c)];
    }
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < MAX; i++)
        fill(nxt[i], nxt[i] + 26, -1);

    string s;
    while (N--)
    {
        cin >> s;
        insert(s);
    }

    int ans = 0;
    while (M--)
    {
        cin >> s;
        ans += check(s);
    }

    cout << ans << '\n';
}

/*
Trie.
구현에 대해서는 https://youtu.be/ZmLe4tc5XRI?si=s5FPNJFO4IHKyFPg 참고.
*/