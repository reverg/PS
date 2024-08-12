#include <iostream>

using namespace std;

int N;
int cnt;
bool col[15], diag1[30], diag2[30];

void place_queens(int y)
{
    if (y == N)
    {
        cnt++;
        return;
    }

    for (int x = 0; x < N; x++)
    {
        if (col[x] || diag1[x + y] || diag2[x - y + N - 1])
            continue;
        col[x] = diag1[x + y] = diag2[x - y + N - 1] = true;
        place_queens(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + N - 1] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    place_queens(0);
    cout << cnt;
}

/*
Well-known. 대각선 탐지 처리를 어떻게 하느냐가 핵심.
*/