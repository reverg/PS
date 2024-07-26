#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int R = 3;
int C = 3;
int matrix[100][100];

void rop()
{
    int nC = 0;
    for (int j = 0; j < R; j++)
    {
        int count[101] = {0};
        for (int i = 0; i < C; i++)
            count[matrix[j][i]]++;

        vector<pair<int, int>> v;
        for (int k = 1; k <= 100; k++)
            if (count[k] != 0)
                v.push_back({count[k], k});

        sort(v.begin(), v.end());
        while (v.size() > 50)
            v.pop_back();

        for (int k = 0; k < v.size(); k++)
        {
            matrix[j][2 * k] = v[k].second;
            matrix[j][2 * k + 1] = v[k].first;
        }

        for (int i = 2 * v.size(); i < 100; i++)
            matrix[j][i] = 0;

        nC = max(nC, 2 * (int)v.size());
    }

    C = nC;
}

void cop()
{
    int nR = 0;
    for (int i = 0; i < C; i++)
    {
        int count[101] = {0};
        for (int j = 0; j < R; j++)
            count[matrix[j][i]]++;

        vector<pair<int, int>> v;
        for (int k = 1; k <= 100; k++)
            if (count[k] != 0)
                v.push_back({count[k], k});

        sort(v.begin(), v.end());
        while (v.size() > 50)
            v.pop_back();

        for (int k = 0; k < v.size(); k++)
        {
            matrix[2 * k][i] = v[k].second;
            matrix[2 * k + 1][i] = v[k].first;
        }

        for (int j = 2 * v.size(); j < 100; j++)
            matrix[j][i] = 0;

        nR = max(nR, 2 * (int)v.size());
    }

    R = nR;
}

int main()
{
    cin >> r >> c >> k;
    for (int j = 0; j < R; j++)
        for (int i = 0; i < C; i++)
            cin >> matrix[j][i];

    int t = 0;
    while (t <= 100)
    {
        if (matrix[r - 1][c - 1] == k)
            break;

        if (R >= C)
            rop();
        else
            cop();

        t++;
    }

    if (t <= 100)
        cout << t << '\n';
    else
        cout << -1 << '\n';
}