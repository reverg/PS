#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    string p;
    cin >> p;

    bool neg = false;
    string num = "";
    int ans = 0;

    for (int i = 0; i <= p.length(); i++)
    {
        if (i == p.length() || !('0' <= p[i] && p[i] <= '9'))
        {
            if (neg)
                ans -= stoi(num);
            else
                ans += stoi(num);
            num = "";
        }
        else
        {
            num += p[i];
        }

        if (p[i] == '-')
            neg = true;
    }

    cout << ans;
}