#include <iostream>

using namespace std;

const int MX = 300000 * 8 + 1;
const int ROOT = 1;
int unused = ROOT + 1;
int nxt[MX][26];
bool fin[MX];

int point, wordNum;
string mxLenWord;
char board[4][4];
bool visited[4][4];
bool chk[MX];
int score[9] = {0, 0, 0, 1, 1, 2, 3, 5, 11};
int dy[8] = {0, -1, 0, 1, 1, -1, -1, 1};
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};

inline int ctoi(char c)
{
    return c - 'A';
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
    fin[cur] = true;
}

void find(int cy, int cx, int cur, string s)
{
    if (cur == -1)
        return;

    if (fin[cur] && !chk[cur])
    {
        chk[cur] = true;
        point += score[s.size()];
        wordNum++;
        if (s.size() > mxLenWord.size())
            mxLenWord = s;
        else if (s.size() == mxLenWord.size() && s < mxLenWord)
            mxLenWord = s;
    }

    for (int k = 0; k < 8; k++)
    {
        int ny = cy + dy[k];
        int nx = cx + dx[k];

        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
            continue;
        if (visited[ny][nx])
            continue;

        visited[ny][nx] = true;
        find(ny, nx, nxt[cur][ctoi(board[ny][nx])], s + board[ny][nx]);
        visited[ny][nx] = false;
    }
}

void solve()
{
    point = 0;
    wordNum = 0;
    mxLenWord = "";
    fill(chk, chk + MX, false);

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            visited[j][i] = true;
            find(j, i, nxt[ROOT][ctoi(board[j][i])], string(1, board[j][i]));
            visited[j][i] = false;
        }
    }

    cout << point << ' ' << mxLenWord << ' ' << wordNum << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < MX; i++)
        fill(nxt[i], nxt[i] + 26, -1);

    int W;
    cin >> W;
    while (W--)
    {
        string word;
        cin >> word;
        insert(word);
    }

    int B;
    cin >> B;
    while (B--)
    {
        for (int j = 0; j < 4; j++)
            cin >> board[j];

        solve();
    }
}

/*
trie와 backtracking을 섞은 문제.
trie의 node 정보를 들고 가면서 종료 조건을 확인하면 된다.
*/