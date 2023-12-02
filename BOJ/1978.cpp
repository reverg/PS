#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        bool sosu = true;

        if (arr[i] == 1)
            sosu = false;

        for (int j = 2; j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
                sosu = false;
        }

        if (sosu == true)
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}