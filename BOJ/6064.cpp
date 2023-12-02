#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int t, M, N, x, y;
    std::cin >> t;
    while (t--)
    {
        std::cin >> M >> N >> x >> y;

        int answer = -1;
        for (int num = x; num <= M * N; num += M)
        {
            if ((num - y) % N == 0)
            {
                answer = num;
                break;
            }
        }
        std::cout << answer << '\n';
    }
}