#include <iostream>
#include <queue>

using namespace std;

int N, W, L;
queue<int> wq;
queue<pair<int, int>> q_crossing;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 아니 세상에 무슨 문제가 길이를 W로 하고 무게를 L로 함???
    // 그래서 바꿨습니다
    cin >> N >> L >> W;
    for (int i = 0; i < N; i++)
    {
        int truck;
        cin >> truck;
        wq.push(truck);
    }

    int t = 0;
    int w_sum = 0;
    while (!wq.empty())
    {
        t++;

        if (!q_crossing.empty() && q_crossing.front().first == t)
        {
            w_sum -= q_crossing.front().second;
            q_crossing.pop();
        }

        if (w_sum + wq.front() <= W)
        {
            w_sum += wq.front();
            q_crossing.push({t + L, wq.front()});
            wq.pop();
        }
    }

    while (!q_crossing.empty())
    {
        t = q_crossing.front().first;
        q_crossing.pop();
    }

    cout << t << '\n';
}