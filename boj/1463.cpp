#include <iostream>

using namespace std;

int make_one(int n)
{
    int arr[1000001];
    arr[0] = arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int min_cost = arr[i - 1];
        if (i % 6 == 0)
        {
            min_cost = min(arr[i / 3], arr[i / 2]);
            min_cost = min(min_cost, arr[i - 1]);
        }
        else if (i % 3 == 0)
            min_cost = min(arr[i / 3], arr[i - 1]);
        else if (i % 2 == 0)
            min_cost = min(arr[i / 2], arr[i - 1]);
        else
            min_cost = arr[i - 1];
        arr[i] = min_cost + 1;
    }
    return arr[n];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    cout << make_one(n);
}