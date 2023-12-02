#include <iostream>

using namespace std;

int n;
long long b;
int mat[5][5];
int temp[5][5];
int ans[5][5] = {0};

// Multiplication: A = A * B
void mult(int A[5][5], int B[5][5])
{
    int temp[5][5];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[i][j] = 0;
            for (int t = 0; t < n; t++)
            {
                temp[i][j] += A[i][t] * B[t][j];
            }
            temp[i][j] %= 1000;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            A[i][j] = temp[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    // get matrix
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        ans[i][i] = 1; // set ans as a identity
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    // get power of matrix
    while (b > 0)
    {
        if (b % 2 != 0)
        {
            mult(ans, mat);
        }
        mult(mat, mat);
        b /= 2;
    }

    // print matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}