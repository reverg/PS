#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char board[1501][1501];
bool visited[1501][1501];
vector<pair<int, int>> swans;
queue<pair<int, int>> swanQ, waterQ;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void meltIce()
{
    int qs = waterQ.size();
    while (qs--)
    {
        int cy = waterQ.front().first;
        int cx = waterQ.front().second;
        waterQ.pop();

        for (int k = 0; k < 4; k++)
        {
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                continue;
            if (board[ny][nx] != 'X')
                continue;

            board[ny][nx] = '.';
            waterQ.push({ny, nx});
        }
    }
}

bool canMeet()
{
    queue<pair<int, int>> boundaryQ;

    while (!swanQ.empty())
    {
        int cy = swanQ.front().first;
        int cx = swanQ.front().second;
        swanQ.pop();

        if (cy == swans[1].first && cx == swans[1].second)
            return true;

        for (int k = 0; k < 4; k++)
        {
            int ny = cy + dy[k];
            int nx = cx + dx[k];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                continue;
            if (visited[ny][nx])
                continue;

            visited[ny][nx] = true;
            if (board[ny][nx] == 'X')
                boundaryQ.push({ny, nx});
            else
                swanQ.push({ny, nx});
        }
    }

    swanQ = boundaryQ;
    return false;
}

int main()
{
    cin >> R >> C;

    for (int j = 0; j < R; j++)
    {
        for (int i = 0; i < C; i++)
        {
            cin >> board[j][i];

            if (board[j][i] == 'L')
                swans.push_back({j, i});
            if (board[j][i] == '.' || board[j][i] == 'L')
                waterQ.push({j, i});
        }
    }

    swanQ.push({swans[0].first, swans[0].second});

    int time = 0;
    while (true)
    {
        if (canMeet())
            break;
        time++;
        meltIce();
    }
    cout << time << '\n';
}

/*
구현이 복잡한 BFS.
물을 담는 waterQ와 백조가 갈 수 있는 경계를 담는 swanQ를 쓴다.
waterQ는 크기만큼 하는 BFS로 물이 있는 구역을 확장한다.
swanQ는 백조가 갈 수 있는 경계를 담아둔건데, 다음 턴에 이 부분이
모두 물이 되므로 거기부터 백조가 도달할 수 있는 새로운 얼음 경계를
찾으면 된다. 중간에 다른 백조를 만나면 멈추고 걸린 시간을 출력.
*/