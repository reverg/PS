#include <iostream>
using namespace std;

int main()
{
    int m, n;
    int sum = 0;
    bool exist = false;
    int min = 0;

    cin >> m;
    cin >> n;

    for (int i = m; i <= n; i++)
    {
        if ((i != 2 && i % 2 == 0) || i == 1)
            continue;

        bool sosu = true;

        for (int j = 3; j < i; j += 2)
        {
            if (i % j == 0)
                sosu = false;
        }

        if (sosu == true)
        {
            sum += i;
            if (exist == false)
            {
                exist = true;
                min = i;
            }
        }
    }

    if (exist == false)
        cout << "-1";
    else
        cout << sum << endl
             << min;

    return 0;
}