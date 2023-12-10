#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> numbers;
int seq[8];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (find(numbers.begin(), numbers.end(), num) == numbers.end())
        {
            numbers.emplace_back(num);
        }
    }
    sort(numbers.begin(), numbers.end());
}

void backtrack(int cnt, int pos)
{
    if (cnt == M)
    {
        for (int i = 0; i < M - 1; i++)
        {
            printf("%d ", seq[i]);
        }
        printf("%d\n", seq[M - 1]);
        return;
    }

    for (int i = pos; i < numbers.size(); i++)
    {
        seq[cnt] = numbers[i];
        backtrack(cnt + 1, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    backtrack(0, 0);
}