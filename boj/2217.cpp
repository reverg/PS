#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), greater<int>());

    int max_weight = 0;
    for (int k = 1; k <= N; k++)
        max_weight = max(max_weight, k * v[k - 1]);

    cout << max_weight << '\n';
}