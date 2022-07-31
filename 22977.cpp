#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    long long x_prev, y_prev;
    cin >> x_prev >> y_prev;
    n--;

    long long x, y;
    long long sum = 0;
    while (n--)
    {
        cin >> x >> y;
        if (x_prev == x)
            sum += max(y - y_prev, (long long)0);
        else
            sum += max(x_prev - x, (long long)0);
        x_prev = x;
        y_prev = y;
    }

    sum *= 2;
    cout << sum;
}