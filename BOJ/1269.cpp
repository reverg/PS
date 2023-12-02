#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::set<int> A, B;
    int input;
    int dup = 0;

    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        std::cin >> input;
        A.insert(input);
    }

    for (int j = 0; j < M; j++)
    {
        std::cin >> input;
        if (A.count(input) != 0)
            dup++;
    }

    std::cout << N + M - dup * 2;
}