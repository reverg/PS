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
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

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