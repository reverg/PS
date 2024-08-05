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
            s.erase(it);
            s.insert(*it - 1);
        }
    }

    cout << s.size() << '\n';
}

/*
그리디 알고리즘. 키 내림차순으로 학생들을 정렬하고,
다음 학생이 허용 가능한 인원수에 가장 가까운 크기의
그룹에 새로운 학생을 넣는다. 키 역순으로 들어가므로
순서대로 넣으면 문제가 생길 여지가 없다.
*/