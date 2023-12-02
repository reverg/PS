#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int N, M;
    std::map<std::string, std::string> m;
    std::string key, value;

    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        std::cin >> key >> value;
        m[key] = value;
    }

    for (int i = 0; i < M; i++)
    {
        std::cin >> key;
        std::cout << m[key] << '\n';
    }
}