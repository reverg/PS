#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;
    while (N--)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), greater<int>());

    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << '\n';
    }
}