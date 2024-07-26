#include <iostream>
#include <queue>

using namespace std;

int N, K;
int min_time = 100000;
int num_paths = 0;
bool visited[100001];

void input()
{
    cin >> N >> K;
}

void hideAndSeek()
{
    queue<pair<int, int>> q;
    q.emplace(N, 0);

    while (!q.empty())
    {
        int cur_pos = q.front().first;
        int cur_time = q.front().second;
        visited[cur_pos] = true;
        q.pop();

        if (cur_pos == K)
        {
            if (min_time > cur_time)
            {
                min_time = cur_time;
                num_paths = 1;
            }
            else if (min_time == cur_time)
            {
                num_paths++;
            }
        }

        if (min_time >= cur_time)
        {
            if (cur_pos + 1 <= 100000 && !visited[cur_pos + 1])
            {
                q.emplace(cur_pos + 1, cur_time + 1);
            }
            if (cur_pos - 1 >= 0 && !visited[cur_pos - 1])
            {
                q.emplace(cur_pos - 1, cur_time + 1);
            }
            if (cur_pos * 2 <= 100000 && !visited[cur_pos * 2])
            {
                q.emplace(cur_pos * 2, cur_time + 1);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();

    hideAndSeek();

    cout << min_time << endl
         << num_paths << endl;
}