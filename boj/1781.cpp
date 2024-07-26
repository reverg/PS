#include <iostream>
#include <queue>

using namespace std;

struct Task
{
    int deadline;
    int ramen;
};

struct compTask
{
    bool operator()(const Task &t1, const Task &t2) const
    {
        if (t1.deadline != t2.deadline)
            return t1.deadline > t2.deadline;
        else
            return t1.ramen < t2.ramen;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<Task, vector<Task>, compTask> pq;
    for (int i = 0; i < N; i++)
    {
        int d, r;
        cin >> d >> r;
        pq.push(Task{d, r});
    }

    int time = 1;
    long long ans = 0;
    priority_queue<int, vector<int>, greater<int>> pqAns;
    while (!pq.empty())
    {
        Task ct = pq.top();
        pq.pop();

        if (ct.deadline >= time)
        {
            pqAns.push(ct.ramen);
            time++;
        }
        else
        {
            if (pqAns.top() < ct.ramen)
            {
                pqAns.pop();
                pqAns.push(ct.ramen);
            }
        }
    }

    while (!pqAns.empty())
    {
        ans += pqAns.top();
        pqAns.pop();
    }

    cout << ans << '\n';
}