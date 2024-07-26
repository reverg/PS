#include <iostream>
#include <queue>

using namespace std;

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inCampus(int y, int x)
{
    return (0 < y) && (y <= N) && (0 < x) && (x <= M);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int str_r, str_c, met = 0;
    char campus[601][601];
    cin >> N >> M;
    for (int j = 1; j <= N; j++)
    {
        for (int i = 1; i <= M; i++)
        {
            cin >> campus[j][i];
            if (campus[j][i] == 'I')
            {
                str_r = j;
                str_c = i;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(make_pair(str_r, str_c));
    campus[str_r][str_c] = 'V';
    while (!q.empty())
    {
        pair<int, int> cur_pos = q.front();
        int cur_y = cur_pos.first;
        int cur_x = cur_pos.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nxt_y = cur_y + dy[i];
            int nxt_x = cur_x + dx[i];
            if (inCampus(nxt_y, nxt_x))
            {
                if (campus[nxt_y][nxt_x] == 'V' || campus[nxt_y][nxt_x] == 'X')
                {
                    continue;
                }
                else if (campus[nxt_y][nxt_x] == 'O')
                {
                    campus[nxt_y][nxt_x] = 'V';
                    q.push(make_pair(nxt_y, nxt_x));
                }
                else if (campus[nxt_y][nxt_x] == 'P')
                {
                    met++;
                    campus[nxt_y][nxt_x] = 'V';
                    q.push(make_pair(nxt_y, nxt_x));
                }
            }
        }
        
    }

    if (met != 0)
        cout << met;
    else
        cout << "TT";

    return 0;
}