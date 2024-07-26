#include <iostream>
using namespace std;

void bunhae(int n)
{
    int div = 0;
    if (n != 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                cout << i << endl;
                div = i;
                break;
            }
        }
        bunhae(n / div);
    }
}

int main()
{
    int n;
    cin >> n;
    bunhae(n);
    return 0;
}