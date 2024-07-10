#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int N;
pair<int, int> student[500001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> student[i].first >> student[i].second;
    sort(student, student + N, greater<pair<int, int>>());

    multiset<int> s; // 중복된 key 허용
    for (int i = 0; i < N; i++)
    {
        // -(인원수)로 넣으면 사람 적은 순으로 정렬됨
        // 허용 가능한 범위에서 가장 큰 집합에 넣기
        auto it = s.lower_bound(-student[i].second + 1);
        if (it == s.end())
            s.insert(-1);
        else
        {
            int ord = *it;
            s.erase(it);
            s.insert(ord - 1);
        }
    }

    cout << s.size() << '\n';
}