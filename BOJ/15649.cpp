#include <iostream>
#include <vector>

void permutation(int n, std::vector<int> &picked, bool included[], int toPick)
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
        if (included[next] == false)
        {
            picked.push_back(next);
            included[next] = true;
            permutation(n, picked, included, toPick - 1);
            picked.pop_back();
            included[next] = false;
        }
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
    permutation(N, picked, included, M);
}