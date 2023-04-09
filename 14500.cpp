#include <iostream>
int main()
{
    int N, M;
    int paper[501][501];

    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            std::cin >> paper[i][j];

    int max_sum = 0;
    // 1 by 4
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M - 3; j++)
        {
            int loc_sum = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3];
            max_sum = std::max(max_sum, loc_sum);
        }
    }

    // 2 by 2
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < M - 1; j++)
        {
            int loc_sum = paper[i][j] + paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1];
            max_sum = std::max(max_sum, loc_sum);
        }
    }

    // 4 by 1
    for (int i = 0; i < N - 3; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int loc_sum = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j];
            max_sum = std::max(max_sum, loc_sum);
        }
    }

    // 2 by 3
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M - 1; j++)
        {
            int part = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
            max_sum = std::max(max_sum, part - paper[i][j] - paper[i + 1][j]);
            max_sum = std::max(max_sum, part - paper[i + 1][j] - paper[i + 2][j]);
            max_sum = std::max(max_sum, part - paper[i][j + 1] - paper[i + 1][j + 1]);
            max_sum = std::max(max_sum, part - paper[i + 1][j + 1] - paper[i + 2][j + 1]);

            max_sum = std::max(max_sum, part - paper[i][j] - paper[i + 2][j + 1]);
            max_sum = std::max(max_sum, part - paper[i + 2][j] - paper[i][j + 1]);

            max_sum = std::max(max_sum, part - paper[i][j] - paper[i + 2][j]);
            max_sum = std::max(max_sum, part - paper[i][j + 1] - paper[i + 2][j + 1]);
        }
    }

    // 3 by 2
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {
            int part = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
            max_sum = std::max(max_sum, part - paper[i][j] - paper[i][j + 1]);
            max_sum = std::max(max_sum, part - paper[i][j + 1] - paper[i][j + 2]);
            max_sum = std::max(max_sum, part - paper[i + 1][j] - paper[i + 1][j + 1]);
            max_sum = std::max(max_sum, part - paper[i + 1][j + 1] - paper[i + 1][j + 2]);

            max_sum = std::max(max_sum, part - paper[i][j] - paper[i + 1][j + 2]);
            max_sum = std::max(max_sum, part - paper[i][j + 2] - paper[i + 1][j]);

            max_sum = std::max(max_sum, part - paper[i][j] - paper[i][j + 2]);
            max_sum = std::max(max_sum, part - paper[i + 1][j] - paper[i + 1][j + 2]);
        }
    }

    std::cout << max_sum << '\n';
}