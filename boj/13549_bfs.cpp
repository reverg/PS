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
            dq.push_front({cur * 2, time});

        if (cur - 1 >= 0 && !visited[cur - 1])
            dq.push_back({cur - 1, time + 1});

        if (cur + 1 <= 100000 && !visited[cur + 1])
            dq.push_back({cur + 1, time + 1});
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    cout << bfs(N, K);
}

/*
0-1 BFS 기본 문제.
0-1 BFS는 매 시점 후보들의 값 차이가 at most 1로, 중간에 값을 끼워넣을 필요가
없어 덱을 쓰는 것이지 기본적으로는 우선순위 큐 기반 다익스트라와 로직이 동일.
따라서 다익스트라와 동일하게 실제 방문 시 visit을 set해야 한다는 것을 주의해야 함.

순간이동을 하면 0초에 가므로 큐의 앞에 넣어줘야 하는데, 덱을 써도 되고 100000 이하의
모든 가능한 순간이동 경우들을 큐에 싹 넣어줘도 된다. 다익스트라 풀이도 가능하나,
O(V+E) 0-1 BFS가 O((V+E)logV) 다익스트라보다 효율적이다. 나머지 풀이 참고.
*/