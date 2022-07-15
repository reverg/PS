#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    int p[1001] = {0};
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    sort(p, p + n + 1);

    int time = 0;
    for (int i = 1; i <= n; i++)
        time += p[i] * (n - i + 1);

    cout << time;
}