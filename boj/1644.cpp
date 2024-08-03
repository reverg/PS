#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

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
            v.push_back(i);
    }
    v.push_back(0);

    sum = v[0];
    cnt = 0;

    int front = 0, back = 0;
    while (v[back] != 0)
    {
        if (sum > n)
            sum -= v[front++];
        else if (sum < n)
            sum += v[++back];
        else
        {
            cnt++;
            sum -= v[front++];
        }
    }

    cout << cnt;
}