#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int N, M, u, v;
    std::cin >> N >> M;
    int connect[101][101] = {0};
    for (int i = 0; i < M; i++)
    {
        std::cin >> u >> v;
        connect[u][v] = connect[v][u] = 1;
    }

    // Floyd-Warshall
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i == j)
                    continue;
                else if (connect[i][k] && connect[k][j])
                {
                    if (!connect[i][j])
                        connect[i][j] = connect[i][k] + connect[k][j];
                    else
                        connect[i][j] = std::min(connect[i][j], connect[i][k] + connect[k][j]);
                }
            }
        }
    }

    int min_kevin = 99 * 99;
    int min_person = 1;
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
            sum += connect[i][j];

        if (min_kevin > sum)
        {
            min_kevin = sum;
            min_person = i;
        }
    }

    std::cout << min_person << '\n';
}