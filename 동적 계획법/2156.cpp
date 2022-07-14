#include <iostream>

using namespace std;

int wine[10001];
int drunken[10001];

int drink(int n)
{
    drunken[1] = wine[1];
    drunken[2] = wine[1] + wine[2];
    for (int i = 3; i <= n; i++)
    {
        drunken[i] = max(drunken[i - 2], drunken[i - 3] + wine[i - 1]) + wine[i];
        drunken[i] = max(drunken[i], drunken[i - 1]);
    }

    return drunken[n];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> wine[i];
    cout << drink(n);
}