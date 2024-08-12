#include <iostream>
#include <vector>

using namespace std;

int K;
int S[13];
vector<int> seq;

void backtrack(int pos, int cnt)
{
    if (cnt == 6)
    {
        for (int num : seq)
            cout << num << ' ';
        cout << '\n';
        return;
    }

    for (int i = pos; i < K; i++)
    {
        seq.push_back(S[i]);
        backtrack(i + 1, cnt + 1);
        seq.pop_back();
    }
}

int main()
{
    while (true)
    {
        cin >> K;
        if (K == 0)
            break;

        for (int i = 0; i < K; i++)
            cin >> S[i];

        backtrack(0, 0);
        cout << '\n';
    }
}