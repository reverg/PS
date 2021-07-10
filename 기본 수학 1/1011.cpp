#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    int x, y;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> x >> y;
        int d = y - x;
        int k_max = (int)sqrt(d);

        if (d == 3)
            cout << "3" << endl;
        else
        {
            if (k_max * k_max == d)
                cout << 2 * k_max - 1 << endl;
            else if (d <= (k_max * k_max + k_max))
                cout << 2 * k_max << endl;
            else
                cout << 2 * k_max + 1 << endl;
        }
    }

    return 0;
}