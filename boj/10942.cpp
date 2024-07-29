#include <iostream>

using namespace std;

int N, M, S, E;
int seq[2001] = {0};
bool palindrome[2001][2001] = {false};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> seq[i];

    // 길이 1: palindrome
    for (int i = 1; i <= N; i++)
        palindrome[i][i] = true;

    // 길이 2: 2개 같으면 palindrome
    for (int i = 1; i <= N - 1; i++)
        palindrome[i][i + 1] = (seq[i] == seq[i + 1]);

    // 길이 3 이상: 양쪽 끝 똑같고 안쪽 palindrome이면 palindrome
    for (int l = 3; l <= N; l++)
    {
        for (int s = 1; s + l - 1 <= N; s++)
        {
            if (palindrome[s + 1][s + l - 2] && (seq[s] == seq[s + l - 1]))
                palindrome[s][s + l - 1] = true;
        }
    }

    cin >> M;
    for (int j = 0; j < M; j++)
    {
        cin >> S >> E;
        cout << palindrome[S][E] << '\n';
    }
}