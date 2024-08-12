#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> candidates;

void backtrack(int cnt)
{
    if (cnt == 0)
    {
        for (int i = 0; i < candidates.size() - 1; i++)
            cout << candidates[i] << ' ';
        cout << candidates[candidates.size() - 1] << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        candidates.emplace_back(numbers[i]);
        backtrack(cnt - 1);
        candidates.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        numbers.emplace_back(tmp);
    }

    sort(numbers.begin(), numbers.end());

    backtrack(M);
}