#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int NcK[1001][1001];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == j || j == 0)
                NcK[i][j] = 1;
            else
                NcK[i][j] = (NcK[i - 1][j] + NcK[i - 1][j - 1]) % 10007;
        }
    }
    cout << NcK[N][K];
    return 0;
}

/*
nCr = nC(r-1) + (n-1)C(r-1)
*/