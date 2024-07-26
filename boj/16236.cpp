#include <iostream>
#include <queue>
#include <memory.h>
#include <tuple>

int space[21][21];
int visited[21][21];
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};
int N, by, bx, shark_size = 2;

int BFS(int y, int x, int shark_size)
{
    visited[y][x] = true;

    std::queue<std::tuple<int, int, int>> q;
    q.push(std::make_tuple(y, x, 0));
    int min_time = 999999;
    while (!q.empty())
    {
        int cur_y, cur_x, cur_time;
        std::tie(cur_y, cur_x, cur_time) = q.front();
        q.pop();

        if (min_time <= cur_time)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = cur_y + dy[i];
            int nx = cur_x + dx[i];
            if (!(1 <= ny && ny <= N && 1 <= nx && nx <= N) || visited[ny][nx] || shark_size < space[ny][nx])
            {
                continue;
            }
            else if (shark_size == space[ny][nx] || space[ny][nx] == 0)
            {
                visited[ny][nx] = true;
                q.push(std::make_tuple(ny, nx, cur_time + 1));
            }
            else
            {
                if (min_time > cur_time + 1)
                {
                    min_time = cur_time + 1;
                    by = ny;
                    bx = nx;
                }
                else
                {
                    if (by > ny || (by == ny && bx > nx))
                    {
                        by = ny;
                        bx = nx;
                    }
                }
                visited[ny][nx] = true;
                q.push(std::make_tuple(ny, nx, cur_time + 1));
            }
        }
    }
    return min_time;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::cin >> N;
    for (int j = 1; j <= N; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            std::cin >> space[j][i];
            if (space[j][i] == 9)
            {
                by = j, bx = i;
                space[j][i] = 0;
            }
        }
    }

    int fish_eaten = 0, ans = 0;
    while (true)
    {
        memset(visited, false, sizeof(visited));
        int time = BFS(by, bx, shark_size);
        if (time != 999999)
        {
            space[by][bx] = 0;
            ans += time;
            fish_eaten++;
            if (fish_eaten == shark_size)
            {
                shark_size++;
                fish_eaten = 0;
            }
        }
        else
        {
            break;
        }
    }

    std::cout << ans << '\n';
}