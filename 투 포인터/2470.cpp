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

    int sol_1, sol_2;
    int err_min = 2000000000;
    int front = 0, back = n - 1;
    while (front != back)
    {
        int sum = arr[front] + arr[back];

        int err = (sum > 0) ? sum : -sum;
        if (err <= err_min)
        {
            sol_1 = arr[front];
            sol_2 = arr[back];
            err_min = err;
        }

        if (sum < 0)
            front++;
        else
            back--;
    }

    cout << sol_1 << ' ' << sol_2;
}