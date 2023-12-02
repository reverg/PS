#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
bool visited[101] = {false};
vector<pair<int, int>> snake;
vector<pair<int, int>> ladder;
int cnt[101] = {0};
queue<int> q;

void bfs()
{
    q.push(1);
    visited[1] == true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++)
        {
            int next = cur + i;
            if (next > 100)
                break;

            for (int j = 0; j < snake.size(); j++)
            {
                if (next == snake[j].first)
                    next = snake[j].second;
            }
            for (int j = 0; j < ladder.size(); j++)
            {
                if (next == ladder[j].first)
                    next = ladder[j].second;
            }

            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
                cnt[next] = cnt[cur] + 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    int str, dst;
    while (N--)
    {
        cin >> str >> dst;
        ladder.emplace_back(str, dst);
    }
    while (M--)
    {
        cin >> str >> dst;
        snake.emplace_back(str, dst);
    }

    bfs();

    cout << cnt[100];
}