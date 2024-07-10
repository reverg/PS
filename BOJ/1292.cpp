#include <iostream>

using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    int arr[1001];
    int k = 1;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            arr[k] = i;
            if (k > 1000)
                break;

            k++;
        }
    }

    int ans = 0;
    for (int i = N; i <= M; i++)
    {
        ans += arr[i];
    }
    cout << ans << '\n';
}