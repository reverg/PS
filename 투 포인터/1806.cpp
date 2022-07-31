#include <iostream>

using namespace std;

int arr[100000];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = arr[0];
    int len = 100001;

    int front = 0, back = 0;
    while (true)
    {
        if (len == 1 || back >= n)
            break;

        if (sum >= s)
        {
            len = min(len, back - front + 1);
            sum -= arr[front++];
        }
        else
        {
            sum += arr[++back];
        }
    }

    cout << ((len == 100001) ? 0 : len);
}