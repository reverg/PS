#include <iostream>

using namespace std;
int sum[100000] = {
    0,
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    int i, j;
    for (int k = 0; k < m; k++)
    {
        cin >> i >> j;
        cout << sum[j] - sum[i - 1] << '\n';
    }
}