#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        int div = 2;
        while (N != 1)
        {
            int cnt = 0;
            while (N % div == 0)
            {
                N /= div;
                cnt++;
            }

            if (cnt != 0)
                cout << div << ' ' << cnt << '\n';

            div++;
        }
    }
}