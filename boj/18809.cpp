#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_SIZE 50
int N, M, G, R;
int board[MAX_SIZE][MAX_SIZE];
vector<pair<int, int>> pos_ground;
int max_flowers = 0;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int bfs(int board[][MAX_SIZE])
{
    // queue setting
    queue<pair<int, int>> q_g;
    queue<pair<int, int>> q_r;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            if (board[j][i] == 3)
                q_g.push({j, i});
            else if (board[j][i] == 4)
                q_r.push({j, i});
        }
    }

    // bfs
    while (true)
    {
        bool newly_spreaded[MAX_SIZE][MAX_SIZE] = {false};
        int q_g_size = q_g.size();
        int q_r_size = q_r.size();
        bool new_cell = false;

        while (q_g_size--)
        {
            int cy = q_g.front().first;
            int cx = q_g.front().second;
            q_g.pop();

            if (board[cy][cx] == 5)
                continue;

            for (int k = 0; k < 4; k++)
            {
                int ny = cy + dy[k];
                int nx = cx + dx[k];
                if (0 <= ny && ny < N && 0 <= nx && nx < M)
                {
                    if (board[ny][nx] == 1 || board[ny][nx] == 2)
                    {
                        board[ny][nx] = 3;
                        newly_spreaded[ny][nx] = true;
                        q_g.push({ny, nx});
                        new_cell = true;
                    }
                }
            }
        }

        while (q_r_size--)
        {
            int cy = q_r.front().first;
            int cx = q_r.front().second;
            q_r.pop();

            for (int k = 0; k < 4; k++)
            {
                int ny = cy + dy[k];
                int nx = cx + dx[k];
                if (0 <= ny && ny < N && 0 <= nx && nx < M)
                {
                    if (board[ny][nx] == 1 || board[ny][nx] == 2)
                    {
                        board[ny][nx] = 4;
                        newly_spreaded[ny][nx] = true;
                        q_r.push({ny, nx});
                        new_cell = true;
                    }
                    else if (board[ny][nx] == 3 && newly_spreaded[ny][nx])
                    {
                        board[ny][nx] = 5;
                    }
                }
            }
        }
        if (!new_cell)
            break;
    }

    // count flowers
    int flowers = 0;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            if (board[j][i] == 5)
                flowers++;
        }
    }

    return flowers;
}

void backtrack(int pos, int g, int r)
{
    // exit condition
    if (pos == pos_ground.size())
    {
        if (g == 0 && r == 0)
        {
            int copied_board[MAX_SIZE][MAX_SIZE];
            std::copy(&board[0][0], &board[0][0] + MAX_SIZE * MAX_SIZE, &copied_board[0][0]);

            int flowers = bfs(copied_board);
            max_flowers = max(flowers, max_flowers);
        }
        return;
    }

    // backtrack
    // use green
    if (g > 0)
    {
        board[pos_ground[pos].first][pos_ground[pos].second] = 3;
        backtrack(pos + 1, g - 1, r);
        board[pos_ground[pos].first][pos_ground[pos].second] = 2;
    }

    // use red
    if (r > 0)
    {
        board[pos_ground[pos].first][pos_ground[pos].second] = 4;
        backtrack(pos + 1, g, r - 1);
        board[pos_ground[pos].first][pos_ground[pos].second] = 2;
    }

    // use nothing
    backtrack(pos + 1, g, r);
}

int main()
{
    cin >> N >> M >> G >> R;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            cin >> board[j][i];
            if (board[j][i] == 2)
                pos_ground.push_back({j, i});
        }
    }

    backtrack(0, G, R);

    cout << max_flowers << '\n';
}

/*
backtracking으로 보드 세팅하는 부분은 next_permutation을 쓰면 정말 간단하게 구현 가능하다.
또한 현재 코드에서는 초록 배양액과 빨강 배양액이 같은 시간에 도달하는 것을 확인하고자 큐를 따로
두고 순차적으로 전파시켰는데, 시간 정보를 따로 저장해주면 하나의 큐에 같이 넣고 bfs를 돌려도 된다.
아니면 2개 큐를 합치되 초록 배양액 칸 수 + 빨강 배양액 칸 수 만큼씩 끊어서 퍼뜨리는 것도 가능할 것이다.
풀이 참조: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x0C/solutions/18809.cpp
*/