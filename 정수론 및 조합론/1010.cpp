#include <iostream>
using namespace std;

int main()
{
    int n, wsite, esite;
    cin >> n;

    for (int t = 0; t < n; t++)
    {
        cin >> wsite >> esite;

        int arr[31][31] = {0, };

        for (int i = 1; i <= wsite; i++)
        {
            for (int j = 1; j <= esite; j++)
            {
                if (i == j)
                    arr[i][j] = 1;
                else if (i == 1)
                    arr[i][j] = j;
                else
                {
                    for (int k = j - 1; k >= i - 1; k--)
                        arr[i][j] += arr[i - 1][k];
                }
            }
        }

        cout << arr[wsite][esite] << endl;
    }
    return 0;
}