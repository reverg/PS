#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, L, R;
int land[50][50];
bool visited[50][50];
queue<vector<pair<int, int>>> unions;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

void init_visited()
{
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            visited[j][i] = false;
}

void make_unions()
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (!visited[j][i])
            {
                queue<pair<int, int>> q;
                vector<pair<int, int>> new_union;

                q.push({j, i});
                new_union.push_back({j, i});
                visited[j][i] = true;

                while (!q.empty())
                {
                    int cy = q.front().first;
                    int cx = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int ny = cy + dy[k];
                        int nx = cx + dx[k];

                        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                            continue;
                        if (visited[ny][nx])
                            continue;

                        int pop_diff = abs(land[cy][cx] - land[ny][nx]);
                        if (L <= pop_diff && pop_diff <= R)
                        {
                            q.push({ny, nx});
                            new_union.push_back({ny, nx});
                            visited[ny][nx] = true;
                        }
                    }
                }

                if (new_union.size() >= 2)
                    unions.push(new_union);
            }
        }
    }
}

bool move_population()
{
    if (unions.empty())
        return false;

    while (!unions.empty())
    {
        auto countries = unions.front();
        unions.pop();

        int pop_sum = 0;
        for (pair<int, int> c : countries)
            pop_sum += land[c.first][c.second];

        int avg_pop = pop_sum / countries.size();
        for (pair<int, int> c : countries)
            land[c.first][c.second] = avg_pop;
    }
    return true;
}

int main()
{
    cin >> N >> L >> R;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            cin >> land[j][i];

    int days = 0;
    while (true)
    {
        init_visited();
        make_unions();
        bool moved = move_population();
        if (!moved)
            break;
        days++;
    }

    cout << days << '\n';
}

/*
union 만들어 질 때마다 이동시켜주는게 훨씬 빠르긴 한데 보기 좋으라고
연합 다 만든 후에 인구 이동시키는 방식으로 함.
*/