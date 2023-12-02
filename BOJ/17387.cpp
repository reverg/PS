#include <iostream>

using namespace std;

pair<long long, long long> A1, A2, B1, B2;

int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C)
{
    long long result = (B.first - A.first) * (C.second - A.second) - (C.first - A.first) * (B.second - A.second);
    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    long long x, y;
    cin >> x >> y;
    A1 = make_pair(x, y);
    cin >> x >> y;
    A2 = make_pair(x, y);
    cin >> x >> y;
    B1 = make_pair(x, y);
    cin >> x >> y;
    B2 = make_pair(x, y);

    // use CCW algorithm
    int A1A2B1 = CCW(A1, A2, B1);
    int A1A2B2 = CCW(A1, A2, B2);
    int B1B2A1 = CCW(B1, B2, A1);
    int B1B2A2 = CCW(B1, B2, A2);

    if (A1A2B1 * A1A2B2 == 0 && B1B2A1 * B1B2A2 == 0)
    {
        if (A1 > A2)
            swap(A1, A2);
        if (B1 > B2)
            swap(B1, B2);

        if (A1 <= B2 && B1 <= A2)
            cout << '1';
        else
            cout << '0';
    }
    else if (A1A2B1 * A1A2B2 <= 0 && B1B2A1 * B1B2A2 <= 0)
        cout << '1';
    else
        cout << '0';
}