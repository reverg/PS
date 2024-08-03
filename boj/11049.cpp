#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int mul[501][501] = {0};
vector<pair<int, int>> v;

int mulMin(int n)
{
    for (int j = 1; j <= n - 1; j++)
    {
        for (int i = 1; i + j <= n; i++)
        {
            mul[i][i + j] = INT32_MAX;
            for (int mid = i; mid < i + j; mid++)
            {
                int cost = mul[i][mid] + mul[mid + 1][i + j];
                cost += v[i].first * v[mid].second * v[i + j].second;
                mul[i][i + j] = min(mul[i][i + j], cost);
            }
        }
    }
    return mul[1][n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n;

    v.emplace_back(0, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> r >> c;
        v.emplace_back(r, c);
    }
    cout << mulMin(n);
}

/*
모든 경우의 수를 따지면 너무 많음. 행렬 i부터 j까지
구간을 나눠서 DP로 연산량 줄일 수 있음
*/