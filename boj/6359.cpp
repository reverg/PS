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

        bool rooms[101] = {false};
        for (int i = 1; i <= N; i++)
            for (int j = i; j <= N; j += i)
                rooms[j] = !rooms[j];

        int ans = 0;
        for (int i = 1; i <= N; i++)
            if (rooms[i])
                ans++;

        cout << ans << '\n';
    }
}