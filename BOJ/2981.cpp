#include <iostream>
using namespace std;

int GCD(int a, int b);

int main()
{
    int n;
    cin >> n;
    int arr[n] = {
        0,
    };
    int yaksu[100000] = {0, };
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            arr[i] = arr[i + 1] - arr[i];
        }
        else
            arr[i] = arr[i] - arr[i + 1];
    }

    for (int i = 1; i < n - 1; i++)
    {
        arr[0] = GCD(arr[0], arr[i]);
    }

    int gcd = arr[0];

    for (int i = 2; i * i <= gcd; i++)
    {
        if (gcd % i == 0)
        {
            cout << i << " ";
            if (gcd != i * i)
            {
                cnt++;
                yaksu[cnt] = gcd / i;
            }
        }
    }

    for (int i = cnt; i > 0; i--)
    {
        cout << yaksu[i] << " ";
    }
    cout << gcd;

    return 0;
}

int GCD(int a, int b)
{
    if (a < b)
    {
        int tmp = b;
        b = a;
        a = tmp;
    }

    while (b != 0)
    {
        a = a % b;
        int tmp = b;
        b = a;
        a = tmp;
    }

    return a;
}