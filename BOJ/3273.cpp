#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int x;
    cin >> x;

    int cnt = 0;
    int front = 0, back = n - 1;
    while (front != back)
    {
        int sum = arr[front] + arr[back];
        if (sum > x)
            back--;
        else if (sum < x)
            front++;
        else
        {
            cnt++;
            front++;
        }
    }

    cout << cnt;
}