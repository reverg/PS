#include <iostream>

using namespace std;

int arr[4000000];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        bool isPrime = true;
        for (int j = 2; (j * j) <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            arr[cnt++] = i;
            sum += i;
        }
    }

    sum = arr[0];
    cnt = 0;

    int front = 0, back = 0;
    while (arr[back] != 0)
    {
        if (sum > n)
            sum -= arr[front++];
        else if (sum < n)
            sum += arr[++back];
        else
        {
            cnt++;
            sum -= arr[front++];
        }
    }

    cout << cnt;
}