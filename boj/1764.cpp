#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::set<std::string> s;
    int N, M;
    std::string input;
    std::vector<std::string> deudbo;

    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        std::cin >> input;
        s.insert(input);
    }

    for (int j = 0; j < M; j++)
    {
        std::cin >> input;
        if (s.count(input) != 0)
        {
            deudbo.push_back(input);
        }
    }

    std::cout << deudbo.size() << '\n';
    std::sort(deudbo.begin(), deudbo.end());
    for (std::string deudboman : deudbo)
    {
        std::cout << deudboman << '\n';
    }
    return 0;
}