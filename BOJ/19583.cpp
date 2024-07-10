#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S, E, Q;
    cin >> S >> E >> Q;

    string nickname, timestamp;
    unordered_map<string, int> attendance;
    int ans = 0;
    while (cin >> timestamp >> nickname)
    {
        if (timestamp <= S)
        {
            attendance[nickname] = 1;
        }
        else if (E <= timestamp && timestamp <= Q)
        {
            if (attendance[nickname] == 1)
            {
                attendance[nickname] = 2;
                ans++;
            }
        }
    }

    cout << ans << '\n';
}