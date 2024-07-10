#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int L, P, V;
    int tc = 0;
    while (++tc)
    {
        cin >> L >> P >> V;
        if (L == 0)
            break;

        int ans = L * (V / P) + min(L, V % P);

        cout << "Case " << tc << ": " << ans << '\n';
    }
}