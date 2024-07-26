#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<long long> v;
    for (int i = 0; i < N; i++)
    {
        long long a;
        cin >> a;
        v.emplace_back(a);
    }

    sort(v.begin(), v.end());

    cout << v[K - 1];
}