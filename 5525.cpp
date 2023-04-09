#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int N, M;
    std::string S;
    std::cin >> N >> M >> S;

    int answer = 0;
    for (int idx = 0; idx <= M - (2 * N + 1); idx++)
    {
        if (S[idx] == 'I')
        {
            int cnt = 0;
            while (S[idx + 1] == 'O' && S[idx + 2] == 'I')
            {
                cnt++;
                if (cnt == N)
                {
                    cnt--;
                    answer++;
                }
                idx += 2;
            }
        }
    }

    std::cout << answer << '\n';
}