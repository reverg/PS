#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;

    int v[11];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
        
    for (int i = n; k > 0; i--)
    {
        cnt += (k / v[i]);
        k %= v[i];
    }

    cout << cnt;
}