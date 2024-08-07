#include <iostream>

using namespace std;

const int ROOT = 1;
int lc[100001];
int rc[100001];
int p[100001];
bool visited[100001] = {false};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b;
        rc[a] = c;
        p[b] = p[c] = a;
    }
    p[ROOT] = -1;

    int endpoint = ROOT;
    while (rc[endpoint] != -1)
        endpoint = rc[endpoint];

    int cur = ROOT;
    int cnt = -1;
    while (true)
    {
        cnt++;
        visited[cur] = true;

        if (lc[cur] != -1 && !visited[lc[cur]])
            cur = lc[cur];
        else if (rc[cur] != -1 && !visited[rc[cur]])
            cur = rc[cur];
        else
        {
            if (cur == endpoint)
                break;
            else
                cur = p[cur];
        }
    }

    cout << cnt << '\n';
}

/*
문제의 유사 중위 순회를 직접 구현해서 답을 구하긴 했으나,
오른쪽 끝까지 가는 간선을 제외하면 모두 2번씩 지나가는 것을
이용해서 (간선 수) * 2 - (오른쪽 끝 깊이)로 간단히 풀 수 있다.
*/