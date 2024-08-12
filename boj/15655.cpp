#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int numbers[8];
vector<int> cand;

void backtrack(int cnt, int pos)
{
    if (cnt == 0)
    {
        for (int i = 0; i < cand.size() - 1; i++)
            cout << cand[i] << ' ';
        cout << cand[cand.size() - 1] << '\n';
        return;
    }

    for (int i = pos; i < N; i++)
    {
        cand.push_back(numbers[i]);
        backtrack(cnt - 1, i + 1);
        cand.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    sort(numbers, numbers + N);

    backtrack(M, 0);
}