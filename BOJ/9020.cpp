#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    bool sosu[10001]; //sosu[i]에 i 할당
    for (int i = 2; i <= 10000; i++)
        sosu[i] = true;
    sosu[0] = false;
    sosu[1] = false;

    for (int i = 2; i <= 100; i++)
    {
        if (sosu[i] == true)
        {
            for (int j = 2 * i; j <= 10000; j += i)
                sosu[j] = false;
        }
    }

    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        for (int j = n / 2; j >= 2; j--)
        {
            if (sosu[j] && sosu[n - j])
            {
                cout << j << " " << n - j << endl;
                break;
            }
        }
    }

    return 0;
}