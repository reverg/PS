#include <iostream>

using namespace std;
int n, m, x;
long long rem[1001] = {
    0,
};
long long sum = 0, tot = 0;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        sum += x;
        sum %= m;
        rem[sum]++;
    }

    for (int i = 0; i < m; i++)
        tot += (rem[i] * (rem[i] - 1)) / 2;

    cout << tot + rem[0];
}