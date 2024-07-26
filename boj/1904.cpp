#include <iostream>

using namespace std;

int bin[1000001];

int binary(int n)
{
    bin[0] = bin[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        bin[i] = bin[i - 1] + bin[i - 2];
        bin[i] %= 15746;
    }
    return bin[n];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    cout << binary(n);
}