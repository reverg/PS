#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        int price[1000001];
        for (int i = 1; i <= N; i++)
            cin >> price[i];

        long long profit = 0;
        int local_max = price[N];
        for (int i = N; i >= 1; i--)
        {
            local_max = max(local_max, price[i]);
            profit += local_max - price[i];
        }

        cout << profit << '\n';
    }
}