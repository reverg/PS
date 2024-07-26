#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    set<string> ss;
    while (N--)
    {
        string in;
        cin >> in;
        sort(in.begin(), in.end());
        ss.insert(in);
    }

    cout << ss.size() << '\n';
}