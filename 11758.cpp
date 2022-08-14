#include <iostream>

using namespace std;

pair<int, int> P[3];

int CCW(pair<int, int> P[3])
{
    pair<int, int> line[2];
    for (int i = 0; i < 2; i++)
        line[i] = make_pair(P[i + 1].first - P[i].first, P[i + 1].second - P[i].second);

    int result = line[0].first * line[1].second - line[0].second * line[1].first;
    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < 3; i++)
        cin >> P[i].first >> P[i].second;

    cout << CCW(P);
}