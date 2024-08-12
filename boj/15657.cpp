#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int numbers[8];
int seq[8];

void backtrack(int cnt, int pos)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << seq[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = pos; i < N; i++)
    {
        seq[cnt] = numbers[i];
        backtrack(cnt + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    sort(numbers, numbers + N);

    backtrack(0, 0);
}