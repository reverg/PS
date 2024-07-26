#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<pair<int, int>> bupum;
int share[51];

int main()
{
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
    {
        int pr;
        cin >> pr;
        bupum.push_back({pr, i});
    }

    sort(bupum.begin(), bupum.end(), greater<pair<int, int>>());

    for (int i = 0; i < min(N, K); i++)
    {
        cout << bupum[i].second << '\n';
        share[bupum[i].second] = bupum[i].second;
    }
    for (int i = 0; i < K - N; i++)
        cout << "0\n";

    for (int i = 1; i <= N; i++)
        cout << share[i] << '\n';
}