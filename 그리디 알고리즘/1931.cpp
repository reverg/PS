#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> meeting;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    int str, fin;
    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> str >> fin;
        meeting.push_back(make_pair(fin, str));
    }

    sort(meeting.begin(), meeting.end());

    int cur_time = meeting[0].first;
    for (int i = 1; i < meeting.size(); i++)
    {
        if (cur_time <= meeting[i].second)
        {
            ans++;
            cur_time = meeting[i].first;
        }
    }

    cout << ans;
}