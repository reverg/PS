#include <iostream>

using namespace std;

int A[100][100], B[100][100];
int ans[100][100] = {0};

void mult(int n, int m, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int t = 0; t < m; t++)
            {
                ans[i][j] += A[i][t] * B[t][j];
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m, k;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    cin >> m >> k;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> B[i][j];
        }
    }

    mult(n, m, k);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}