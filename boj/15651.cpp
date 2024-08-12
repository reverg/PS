#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> picked;

void backtrack(int toPick)
{
    if (toPick == 0)
    {
        for (auto elem : picked)
            cout << elem << ' ';
        cout << '\n';
        return;
    }

    for (int next = 1; next <= N; next++)
    {
        picked.push_back(next);
        backtrack(toPick - 1);
        picked.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    backtrack(M);
}