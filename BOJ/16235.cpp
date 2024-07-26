#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int A[12][12];
int yangbun[12][12];
vector<int> trees[12][12];

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring_summer()
{
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            vector<int> &cv = trees[r][c];
            int idx = (int)cv.size() - 1;

            // spring
            for (; idx >= 0; idx--)
            {
                if (yangbun[r][c] < cv[idx])
                    break;
                yangbun[r][c] -= cv[idx];
                cv[idx]++;
            }

            // summer
            for (int i = 0; i <= idx; i++)
                yangbun[r][c] += cv[i] / 2;
            cv.erase(cv.begin(), cv.begin() + idx + 1);
        }
    }
}

void fall_winter()
{
    for (int r = 1; r <= N; r++)
    {
        for (int c = 1; c <= N; c++)
        {
            // fall
            for (int t : trees[r][c])
            {
                if (t % 5 != 0)
                    continue;

                for (int k = 0; k < 8; k++)
                    trees[r + dr[k]][c + dc[k]].push_back(1);
            }

            // winter
            yangbun[r][c] += A[r][c];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
            cin >> A[r][c];

    while (M--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }

    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
            yangbun[r][c] = 5;

    while (K--)
    {
        spring_summer();
        fall_winter();
    }

    int ans = 0;
    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
            ans += trees[r][c].size();
    cout << ans << '\n';
}