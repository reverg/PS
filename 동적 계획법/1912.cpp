#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, z;
    long long part = -1000;
    long long big = -1000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> z;
        if (z >= 0)
            part = (part > 0) ? part + z : z;
        else
            part = (part > 0) ? part + z : z;
        if (part > big)
            big = part;
    }
    cout << big << '\n';
}