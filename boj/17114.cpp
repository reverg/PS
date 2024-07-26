// reference : https://velog.io/@vkdldjvkdnj/boj17114
#include <iostream>
#include <queue>

using namespace std;

struct Dir
{
    int dw, dv, du, dt, ds, dr, dq, dp, do_, dn, dm;
};

struct Element
{
    int days, w, v, u, t, s, r, q, p, o, n, m;
};

Dir dir[22] = {{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
               {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
               {0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
               {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
               {0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0},
               {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
               {0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0},
               {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
               {0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0},
               {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int M, N, O, P, Q, R, S, T, U, V, W;
    cin >> M >> N >> O >> P >> Q >> R >> S >> T >> U >> V >> W;

    int tomatoes[W][V][U][T][S][R][Q][P][O][N][M];
    for (int w = 0; w < W; w++)
        for (int v = 0; v < V; v++)
            for (int u = 0; u < U; u++)
                for (int t = 0; t < T; t++)
                    for (int s = 0; s < S; s++)
                        for (int r = 0; r < R; r++)
                            for (int q = 0; q < Q; q++)
                                for (int p = 0; p < P; p++)
                                    for (int o = 0; o < O; o++)
                                        for (int n = 0; n < N; n++)
                                            for (int m = 0; m < M; m++)
                                                cin >> tomatoes[w][v][u][t][s][r][q][p][o][n][m];

    queue<Element> tomato_q;
    int rest = 0;
    for (int w = 0; w < W; w++)
        for (int v = 0; v < V; v++)
            for (int u = 0; u < U; u++)
                for (int t = 0; t < T; t++)
                    for (int s = 0; s < S; s++)
                        for (int r = 0; r < R; r++)
                            for (int q = 0; q < Q; q++)
                                for (int p = 0; p < P; p++)
                                    for (int o = 0; o < O; o++)
                                        for (int n = 0; n < N; n++)
                                            for (int m = 0; m < M; m++)
                                            {
                                                if (tomatoes[w][v][u][t][s][r][q][p][o][n][m] == 1)
                                                    tomato_q.push({0, w, v, u, t, s, r, q, p, o, n, m});
                                                else if (tomatoes[w][v][u][t][s][r][q][p][o][n][m] == 0)
                                                    rest++;
                                            }

    int answer;
    while (!tomato_q.empty())
    {
        auto [days, w, v, u, t, s, r, q, p, o, n, m] = tomato_q.front();
        tomato_q.pop();
        answer = days;
        for (auto [dw, dv, du, dt, ds, dr, dq, dp, do_, dn, dm] : dir)
            if (0 <= w + dw && w + dw < W && 0 <= v + dv && v + dv < V && 0 <= u + du && u + du < U && 0 <= t + dt && t + dt < T && 0 <= s + ds && s + ds < S && 0 <= r + dr && r + dr < R && 0 <= q + dq && q + dq < Q && 0 <= p + dp && p + dp < P && 0 <= o + do_ && o + do_ < O && 0 <= n + dn && n + dn < N && 0 <= m + dm && m + dm < M && tomatoes[w + dw][v + dv][u + du][t + dt][s + ds][r + dr][q + dq][p + dp][o + do_][n + dn][m + dm] == 0)
            {
                tomato_q.push({days + 1, w + dw, v + dv, u + du, t + dt, s + ds, r + dr, q + dq, p + dp, o + do_, n + dn, m + dm});
                tomatoes[w + dw][v + dv][u + du][t + dt][s + ds][r + dr][q + dq][p + dp][o + do_][n + dn][m + dm] = 1;
                rest--;
            }
    }

    cout << (rest ? -1 : answer) << '\n';
}

/*
0~mnopqurstuvw로 index 하나만 만들어서 하는 방법 시도했는데
차원 밖으로 벗어나는거 처리하기가 까다로워서 포기함.
*/