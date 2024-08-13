#include <iostream>

using namespace std;

int N;
int selection[100001];
int selected[100001];

void dfs(int x)
{
    int cur = x;
    while (true)
    {
        selected[cur] = x;
        cur = selection[cur];

        if (selected[cur] == x) // cycle 1바퀴 돎
        {
            while (selected[cur] != -1) // cycle엘 표시
            {
                selected[cur] = -1;
                cur = selection[cur];
            }
            return;
        }
        else if (selected[cur] != 0) // cycle 아닌 노드 만남
            return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> N;

        for (int i = 1; i <= N; i++)
            cin >> selection[i];

        fill(selected, selected + N + 1, 0);

        for (int i = 1; i <= N; i++)
            if (selected[i] == 0)
                dfs(i);

        int cnt = 0;
        for (int i = 1; i <= N; i++)
            if (selected[i] != -1)
                cnt++;

        cout << cnt << '\n';
    }
}

/*
상세 풀이는 https://blog.encrypted.gg/499 참고.
위상정렬을 마친 후 indeg != 0인 원소 수를 찾는 방법도 있다.
(cycle은 indeg와 outdeg가 맞물려있어서 위상정렬 처리 안 됨)
*/