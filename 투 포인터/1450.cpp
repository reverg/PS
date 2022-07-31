#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[30] = {0};
vector<long long> v1, v2;
long long ans = 0;

void getComb(long long start, long long fin, vector<long long> &v, long long sum)
{
    if (start > fin)
    {
        v.emplace_back(sum);
        return;
    }
    else
    {
        getComb(start + 1, fin, v, sum);
        getComb(start + 1, fin, v, sum + arr[start]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    long long n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    getComb(0, n / 2, v1, 0);
    getComb((n / 2) + 1, n - 1, v2, 0);
    sort(v2.begin(), v2.end());

    for (int i = 0; i < v1.size(); i++)
        ans += upper_bound(v2.begin(), v2.end(), c - v1[i]) - v2.begin();

    cout << ans;
}