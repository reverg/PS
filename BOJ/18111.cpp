#include <iostream>

int main()
{
    int N, M, B;
    int t = 999999999, h = 0, h_max = 0, h_min = 256;
    std::cin >> N >> M >> B;

    int map[500][500];
    for (int j = 0; j < M; j++)
    {
        for (int i = 0; i < N; i++)
        {
            std::cin >> map[j][i];
            if (map[j][i] < h_min)
                h_min = map[j][i];
            if (map[j][i] > h_max)
                h_max = map[j][i];
        }
    }

    for (int k = h_min; k <= h_max; k++)
    {
        int less = 0, more = 0;
        for (int j = 0; j < M; j++)
        {
            for (int i = 0; i < N; i++)
            {
                less += k > map[j][i] ? k - map[j][i] : 0;
                more += k < map[j][i] ? map[j][i] - k : 0;
            }
        }
        if (more + B < less)
            continue;

        if (t >= 2 * more + less)
        {
            t = 2 * more + less;
            h = k;
        }
    }

    std::cout << t << " " << h << std::endl;
}