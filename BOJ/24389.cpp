#include <iostream>

using namespace std;

int bitcnt(int x)
{
    int ret = 0;
    for (int i = 0; i < 32; i++)
        ret += (x >> i) & 1;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    cout << bitcnt(N ^ (~N + 1)) << '\n';
}