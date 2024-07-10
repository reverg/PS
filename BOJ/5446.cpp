#include <iostream>
#include <vector>

using namespace std;

const int MX = 2 * 1000 * 20 + 3;
const int ROOT = 1;
int unused = ROOT + 1;
int nxt[MX][63];
bool cannotRemove[MX];
bool chk[MX];

int ctoi(char c)
{
    if ('a' <= c && c <= 'z')
        return c - 'a';
    else if ('A' <= c && c <= 'Z')
        return c - 'A' + 26;
    else if ('0' <= c && c <= '9')
        return c - '0' + 52;
    else // c == '.'
        return 62;
}

void insert(string &s, bool locked)
{
    int cur = ROOT;
    for (char c : s)
    {
        cannotRemove[cur] = locked;
        int idx = ctoi(c);
        if (nxt[cur][idx] == -1)
            nxt[cur][idx] = unused++;
        cur = nxt[cur][idx];
    }
    cannotRemove[cur] = locked;
    chk[cur] = !locked;
}

int countRemove(int cur)
{
    if (!cannotRemove[cur])
        return 1;

    int cnt = chk[cur];
    for (int i = 0; i < 63; i++)
    {
        if (nxt[cur][i] != -1)
            cnt += countRemove(nxt[cur][i]);
    }
    return cnt;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        unused = ROOT + 1;
        for (int i = 0; i < MX; i++)
            fill(nxt[i], nxt[i] + 63, -1);
        fill(cannotRemove, cannotRemove + MX, false);
        fill(chk, chk + MX, false);

        int N1, N2;
        cin >> N1;

        while (N1--)
        {
            string s;
            cin >> s;
            insert(s, false);
        }

        cin >> N2;
        while (N2--)
        {
            string s;
            cin >> s;
            insert(s, true);
        }

        cout << countRemove(ROOT) << '\n';
    }
}

/*
Trie. 각 노드별로 wildcard를 사용 가능한지 따로 저장해준다. (cannotRemove)
지우면 안되는 파일들을 trie에 넣을 때 지나치는 node들의 cannotRemove를
false로 바꿔주면 된다. 이후 root부터 dfs로 몇 번의 rm을 써야 하는지 확인한다.
cannotRemove가 false면 지우면 안되는 파일이 없으므로 wildcard를 써서 1번에 지우고,
아니면 자식으로 더 내려가서 확인하고 지워준다.
*/