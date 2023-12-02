#include <iostream>
#include <queue>

using namespace std;

int ans = 0;
int stat[8];
bool used[8];
vector<int> v;

bool CCW(int a, int b, int c)
{
    // y = -(c/a)x + c, y = x
    // (a+c)x = ac
    // if sqrt(b) < x, false
    // check (a+c)^2 * b >= (ac)^2
    return ((long long)(a + c) * (a + c) * b * b >= (long long)2 * a * a * c * c);
}

bool check(vector<int> v)
{
    for (int i = 0; i < 8; i++)
        if (!CCW(v[i], v[(i + 1) % 8], v[(i + 2) % 8]))
            return false;

    return true;
}

void graph(int cnt)
{
    if (cnt == 8)
    {
        if (check(v))
            ans++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (used[i])
            continue;

        used[i] = true;
        v.emplace_back(stat[i]);
        graph(cnt + 1);
        v.pop_back();
        used[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < 8; i++)
        cin >> stat[i];

    graph(0);

    cout << ans;
}