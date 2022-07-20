#include <iostream>

using namespace std;
#define PRIME 1000000007;

long long n;
long long fib[2][2] = {1, 1, 1, 0}; // F_n = F_(n-1) + F_(n-2)
long long ans[2][2] = {1, 0, 0, 1}; // identity matrix

// Multiplication: A = A * B
void mult(long long A[2][2], long long B[2][2])
{
    long long temp[2][2] = {0, 0, 0, 0};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int t = 0; t < 2; t++)
            {
                temp[i][j] += A[i][t] * B[t][j];
            }
            temp[i][j] %= PRIME;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            A[i][j] = temp[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> n;

    while (n > 0)
    {
        if (n % 2 != 0)
        {
            mult(ans, fib);
        }
        mult(fib, fib);
        n /= 2;
    }

    cout << ans[0][1];
}