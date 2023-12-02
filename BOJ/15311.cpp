#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cout << 2000 << '\n';
    for (int i = 1; i <= 1000; i++)
        cout << 1 << ' ';
    for (int i = 1; i <= 1000; i++)
        cout << 1000 << ' ';
}