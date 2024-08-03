#include <iostream>

using namespace std;

int route[502][502] = {0};
int height[502][502] = {0};

int downCourse(int i, int j)
{
    if (route[i][j] == -1)
    {
        route[i][j] = 0;
        if (height[i][j] < height[i - 1][j])
            route[i][j] += downCourse(i - 1, j);
        if (height[i][j] < height[i][j - 1])
            route[i][j] += downCourse(i, j - 1);
        if (height[i][j] < height[i + 1][j])
            route[i][j] += downCourse(i + 1, j);
        if (height[i][j] < height[i][j + 1])
            route[i][j] += downCourse(i, j + 1);
    }
    return route[i][j];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> height[i][j];
            route[i][j] = -1;
        }
    }

    height[0][1] = 10001;
    route[0][1] = 1;

    cout << downCourse(m, n) << '\n';
}

/*
DFS + DP. O(MN)으로 끝난다. 높이 순으로 우선 순위 큐에 넣고
BFS를 써도 되긴 하지만, 정렬 과정이 있어서 시간복잡도가
O(MNlog(MN))으로 안 좋다.
*/