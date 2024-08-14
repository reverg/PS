#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int H, W;
char building[102][102];
int visited[102][102];
unordered_set<char> keys;
unordered_map<char, vector<pair<int, int>>> doors;
int document_cnt;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void bfs()
{
    queue<pair<int, int>> q;
    visited[0][0] = true;
    q.push({0, 0});

    while (!q.empty())
    {
        auto [cy, cx] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int ny = cy + dy[d];
            int nx = cx + dx[d];

            if (0 > ny || ny > H + 1 || 0 > nx || nx > W + 1)
                continue;
            if (visited[ny][nx] || building[ny][nx] == '*')
                continue;

            if ('A' <= building[ny][nx] && building[ny][nx] <= 'Z') // doors
            {
                char door = building[ny][nx];
                char correspond_key = door - 'A' + 'a';
                if (keys.count(correspond_key))
                {
                    building[ny][nx] = '.';
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
                else
                    doors[correspond_key].push_back({ny, nx});
            }
            else if ('a' <= building[ny][nx] && building[ny][nx] <= 'z') // keys
            {
                char key = building[ny][nx];
                keys.insert(key);
                for (auto [door_y, door_x] : doors[key])
                {
                    building[door_y][door_x] = '.';
                    building[door_y][door_x] = true;
                    q.push({door_y, door_x});
                }

                building[ny][nx] = '.';
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
            else if (building[ny][nx] == '$')
            {
                document_cnt++;
                building[ny][nx] = '.';
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
            else
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        keys.clear();
        doors.clear();
        document_cnt = 0;

        cin >> H >> W;
        for (int j = 0; j < H + 2; j++)
        {
            fill(building[j], building[j] + W + 2, '.');
            fill(visited[j], visited[j] + W + 2, false);
        }

        for (int j = 1; j <= H; j++)
            for (int i = 1; i <= W; i++)
                cin >> building[j][i];

        string own_keys;
        cin >> own_keys;
        for (int i = 0; i < own_keys.size(); i++)
            keys.insert(own_keys[i]);

        bfs();

        cout << document_cnt << '\n';
    }
}

/*
키를 주워서 문을 여는 BFS 문제.
문을 만났는데 키가 있으면 바로 열어버리고, 없으면 저장해뒀다
나중에 키가 생겼을 때 저장해둔 문을 다 열어버리면 된다.
지금까지 확인된 위치가 모두 방문 가능한 지점들이므로 새로
열린 곳을 큐에 넣어주면 자연스럽게 점점 확장된다.
*/