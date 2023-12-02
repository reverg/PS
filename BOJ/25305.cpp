#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int score[1000];
    for (int i = 0; i < N; i++)
        cin >> score[i];

    sort(score, score + N, greater<>());

    cout << score[K - 1];
}