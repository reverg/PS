#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int numbers[8];
vector<int> cands;

void backtrack(int cnt)
{
    if (cnt == 0)
    {
        for (int i = 0; i < cands.size() - 1; i++)
            cout << cands[i] << ' ';
        cout << cands[cands.size() - 1] << '\n';
        return;
    }

    int prev = -1;
    for (int i = 0; i < N; i++)
    {
        if (prev != numbers[i])
        {
            cands.emplace_back(numbers[i]);
            prev = numbers[i];
            backtrack(cnt - 1);
            cands.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    sort(numbers, numbers + N);

    backtrack(M);
}