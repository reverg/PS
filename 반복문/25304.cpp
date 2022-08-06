#include <iostream>
using namespace std;

int main()
{
    int X, N;
    cin >> X >> N;

    int a, b;
    while (N--)
    {
        cin >> a >> b;
        X -= a * b;
    }

    cout << ((X == 0) ? "Yes" : "No");
}