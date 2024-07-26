#include <iostream>
#include <vector>

using namespace std;

int N;
string S;
vector<int> parts;
int fibo[21] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,
                377, 610, 987, 1597, 2584, 4181, 6765, 10946};

bool hasLong(int idx)
{
    return S[idx] == 'l' && S[idx + 1] == 'o' && S[idx + 2] == 'n' && S[idx + 3] == 'g';
}

int main()
{
    cin >> N;
    cin >> S;

    int idx = 0;
    while (idx + 3 < N)
    {
        int rep_long = 0;

        while (idx + 3 < N && S[idx] != 'l')
            idx++;

        while (idx + 3 < N && hasLong(idx))
        {
            rep_long++;
            idx += 4;
        }

        if (rep_long >= 2)
        {
            parts.push_back(rep_long);
            rep_long = 0;
        }
        idx++;
    }

    int ans = 1;
    for (int c : parts)
        ans *= fibo[c];

    cout << ans << '\n';
}