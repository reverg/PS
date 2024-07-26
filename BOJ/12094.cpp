#include <bits/stdc++.h>
using namespace std;

int board[21][21];
int n;
int ans = 0;

void rotate()
{ // board를 시계 방향으로 90도 회전하는 함수
    int tmp[21][21];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tmp[n - 1 - j][i];
}

bool tilt(int dir)
{
    while (dir--)
        rotate();

    bool changed = false;
    for (int i = 0; i < n; i++)
    {
        int tilted[21] = {}; // board[i]를 왼쪽으로 기울인 결과를 저장할 변수
        int idx = 0;         // tilted 배열에서 어디에 삽입해야 하는지 가리키는 변수
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            if (tilted[idx] == 0) // 삽입할 위치가 비어있을 경우
                tilted[idx] = board[i][j];
            else if (tilted[idx] == board[i][j]) // 같은 값을 갖는 블록이 충돌할 경우
                tilted[idx++] *= 2;
            else // 다른 값을 갖는 블록이 충돌
                tilted[++idx] = board[i][j];
        }
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] != tilted[j])
                changed = true;
            board[i][j] = tilted[j]; // board[i]에 tilted를 덮어씀
        }
    }

    return changed;
}

void undo_board(int temp[][20])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = temp[i][j];
}

void backtrack(int cnt)
{
    int tmp_board[20][20];
    int cur_max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp_board[i][j] = board[i][j];
            cur_max = max(cur_max, board[i][j]);
        }
    }

    ans = max(ans, cur_max);
    if (cnt == 10)
        return;
    if (cur_max * (1 << (10 - cnt)) <= ans) // 끝까지 가도 현재 최대 못 넘는 경우
        return;

    for (int dir = 0; dir < 4; dir++)
    {
        bool changed = tilt(dir);
        if (changed)
        {
            backtrack(cnt + 1);
            undo_board(tmp_board);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    backtrack(0);

    cout << ans << '\n';
}

/*
12100의 Hard 버전.
12100은 이동시킨 후에 결과가 똑같아도 따로 처리해 줄 필요가 없었지만,
이 문제는 시간이 부족해서 확인해줘야 한다. 추가적으로 끝까지 가더라도
기존의 최대값을 넘을 수 없는 경우들은 바로 멈추게 만들었다.
코드는 2개의 reference가 적절히 섞여있다.
12100 reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0D/12100.cpp
12094 reference: https://seokjin2.tistory.com/112
*/