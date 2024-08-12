#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> picked;
bool included[9];

void permutation(int toPick)
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
        if (included[next] == false)
        {
            picked.push_back(next);
            included[next] = true;
            permutation(toPick - 1);
            picked.pop_back();
            included[next] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    permutation(M);
}