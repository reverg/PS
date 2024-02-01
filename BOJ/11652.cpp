#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    map<long long, long long> m;
    for (int i = 0; i < N; i++)
    {
        long long k;
        cin >> k;
        m[k]++;
    }

    long long maxcnt = 0;
    long long ans = 0;
    for (auto l : m)
    {
        if (l.second > maxcnt)
        {
            maxcnt = l.second;
            ans = l.first;
        }
    }

    cout << ans;
}