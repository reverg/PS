#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    string name;
    int korean;
    int english;
    int math;
};

bool comp(Student a, Student b)
{
    if (a.korean != b.korean)
        return a.korean > b.korean;
    else if (a.english != b.english)
        return a.english < b.english;
    else if (a.math != b.math)
        return a.math > b.math;
    else
        return a.name < b.name;
}

int main()
{
    int N;
    cin >> N;

    vector<Student> v;
    string n;
    int k, e, m;
    for (int i = 0; i < N; i++)
    {
        cin >> n >> k >> e >> m;
        v.emplace_back(Student{n, k, e, m});
    }

    sort(v.begin(), v.end(), comp);

    for (auto i : v)
    {
        cout << i.name << '\n';
    }
}
