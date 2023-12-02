#include <iostream>
#include <vector>

void rep_permutation(int n, std::vector<int> &picked, bool included[], int toPick)
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

    for (int next = 1; next <= n; next++)
    {
        picked.push_back(next);
        rep_permutation(n, picked, included, toPick - 1);
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
    bool included[9] = {
        true,
    };
    rep_permutation(N, picked, included, M);
}