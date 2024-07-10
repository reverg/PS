#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, M, L;
    cin >> N >> M >> L;

    int hugaeso[N + 2];
    for (int i = 1; i <= N; i++)
        cin >> hugaeso[i];
    hugaeso[0] = 0;
    hugaeso[N + 1] = L;
    sort(hugaeso, hugaeso + N + 2);

    int ans = 1;
    int low = 1;
    int high = L;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        int new_hugaeso = 0;
        for (int i = 0; i < N + 1; i++)
            new_hugaeso += (hugaeso[i + 1] - hugaeso[i] - 1) / mid;

        if (new_hugaeso > M)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }

    cout << ans << '\n';
}