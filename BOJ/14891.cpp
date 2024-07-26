#include <iostream>

using namespace std;

int top_idx[4] = {0, 0, 0, 0};
int topni[4][8];

int pos(int num)
{
    if (num < 0)
        return num + 8;
    else if (num >= 8)
        return num - 8;
    else
        return num;
}

void rotate(int num, int dir)
{
    int dirs[4] = {0};
    dirs[num] = dir;

    // 왼쪽 톱니들 회전 방향 정하기
    int idx = num;
    while (idx > 0)
    {
        if (topni[idx][pos(top_idx[idx] - 2)] == topni[idx - 1][pos(top_idx[idx - 1] + 2)])
            break;
        dirs[idx - 1] = -dirs[idx];
        idx--;
    }

    // 오른쪽 톱니들 회전 방향 정하기
    idx = num;
    while (idx < 3)
    {
        if (topni[idx][pos(top_idx[idx] + 2)] == topni[idx + 1][pos(top_idx[idx + 1] - 2)])
            break;
        dirs[idx + 1] = -dirs[idx];
        idx++;
    }

    // 회전시키기
    for (int i = 0; i < 4; i++)
        top_idx[i] = pos(top_idx[i] - dirs[i]);
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
            topni[i][j] = s[j] - '0';
    }

    int K;
    cin >> K;
    while (K--)
    {
        int num, dir;
        cin >> num >> dir;
        rotate(num - 1, dir);
    }

    int score = 0;
    for (int i = 0; i < 4; i++)
        if (topni[i][top_idx[i]] == 1)
            score += (1 << i);

    cout << score << '\n';
}