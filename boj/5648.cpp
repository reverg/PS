#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    long long arr[1000001];
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        reverse(s.begin(), s.end());
        arr[i] = stol(s);
    }

    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
}
