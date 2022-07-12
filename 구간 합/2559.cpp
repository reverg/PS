#include <iostream>

using namespace std;
int sum[100000] = {
    0,
};
int ans = -10000000;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    int part = 0;
    for (int i = 0; i < n - k + 1; i++)
    {
        part = sum[k + i] - sum[i];
        if (part > ans)
            ans = part;
    }

    cout << ans;
}