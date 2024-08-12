#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K;
int S[13];
int chk[13];

int main()
{
    while (true)
    {
        cin >> K;
        if (K == 0)
            break;

        for (int i = 0; i < K; i++)
            cin >> S[i];
        for (int i = 6; i < K; i++)
            chk[i] = 1;

        do
        {
            for (int i = 0; i < K; i++)
                if (chk[i] == 0)
                    cout << S[i] << ' ';
            cout << '\n';
        } while (next_permutation(chk, chk + K));
        cout << '\n';
    }
}