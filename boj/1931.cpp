#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> meeting;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

/*
유명한 그리디 문제. 회의가 일찍 끝나는 순서로 정렬해야 한다.
증명은 https://www.youtube.com/watch?v=vw4gqeM4UGs 참고.
*/