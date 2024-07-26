#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (v.empty() || num > v.back())
            v.emplace_back(num);
        else
        {
            int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[idx] = num;
        }
    }

    cout << v.size();
}