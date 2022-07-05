#include <iostream>
#include <vector>

void rep_combination(int n, std::vector<int> &picked, int toPick)
{
    if (toPick == 0)
    {
        for (auto elem : picked)
        {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
        return;
    }

    int smallest = picked.empty() ? 1 : picked.back();

    for (int next = smallest; next <= n; next++)
    {
        picked.push_back(next);
        rep_combination(n, picked, toPick - 1);
        picked.pop_back();
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::vector<int> picked;
    std::cin >> N >> M;
    rep_combination(N, picked, M);
}