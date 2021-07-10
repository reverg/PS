#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    if (n == 4 || n == 7)
        cout << "-1";
    else
    {
        switch (n % 5)
        {
        case 0:
            cout << n / 5;
            break;
        case 1:
            cout << n / 5 + 1;
            break;
        case 2:
            cout << n / 5 + 2;
            break;
        case 3:
            cout << n / 5 + 1;
            break;
        case 4:
            cout << n / 5 + 2;
            break;
        }
    }
}