#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
int numbers[8];
bool inside[8] = {false};
std::vector<int> ans;

void Backtrack(int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < ans.size(); i++)
            std::cout << ans[i] << ' ';
        std::cout << '\n';
    }

    for (int i = 0; i < N; i++)
    {
        if (inside[i])
            continue;
            
        inside[i] = true;
        ans.push_back(numbers[i]);
        Backtrack(cnt + 1);
        ans.pop_back();
        inside[i] = false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false), std::cin.tie(NULL), std::cout.tie(NULL);

    std::cin >> N >> M;
    for (int i = 0; i < N; i++)
        std::cin >> numbers[i];
    std::sort(numbers, numbers + N);

    Backtrack(0);
}