#include <iostream>
#include <deque>

using namespace std;

int N, K;
bool visited[100001] = {false};
deque<pair<int, int>> dq;

int bfs(int N, int K)
{
    dq.push_back(make_pair(N, 0));

    while (!dq.empty())
    {
        int cur = dq.front().first;
        int time = dq.front().second;
        visited[cur] = true;
        dq.pop_front();

        if (cur == K)
            return time;

        if (cur * 2 <= 100000 && !visited[cur * 2])
            dq.push_front(make_pair(cur * 2, time));

        if (cur - 1 >= 0 && !visited[cur - 1])
            dq.push_back(make_pair(cur - 1, time + 1));

        if (cur + 1 <= 100000 && !visited[cur + 1])
            dq.push_back(make_pair(cur + 1, time + 1));
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    cout << bfs(N, K);
}