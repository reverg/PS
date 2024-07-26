#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int numbers[8];
int seq[8];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    sort(&numbers[0], &numbers[N]);
}

void backtrack(int cnt, int pos)
{
    if (cnt == M)
    {
        for (int i = 0; i < M - 1; i++)
        {
            printf("%d ", seq[i]);
        }
        printf("%d\n", seq[M - 1]);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    backtrack(0, 0);
}