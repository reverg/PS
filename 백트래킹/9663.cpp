#include <iostream>

using namespace std;

int n, cnt;
bool col[15], diag1[30], diag2[30];

void search(int y)
{
    if (y == n)
    {
        cnt++;
        return;
    }

    for (int x = 0; x < n; x++)
    {
        if (col[x] || diag1[x + y] || diag2[x - y + n - 1])
            continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = true;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    search(0);
    cout << cnt;
}