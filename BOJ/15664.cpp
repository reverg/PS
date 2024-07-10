#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> cands;

void backtrack(int cnt, int pos)
{
    if (cnt == 0)
    {
        for (int i = 0; i < cands.size() - 1; i++)
            cout << cands[i] << ' ';
        cout << cands[cands.size() - 1] << '\n';

        return;
    }

    int prev = -1;
    for (int i = pos; i < N; i++)
    {
        if (prev != numbers[i])
        {
            prev = numbers[i]; // do not put same value twice
            cands.emplace_back(numbers[i]);
            backtrack(cnt - 1, i + 1);
            cands.pop_back();
        }
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

    backtrack(M, 0);
}