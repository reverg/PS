#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int numbers[8];
vector<int> candidates;

void backtrack(int cnt, int pos)
{
    if (cnt == 0)
    {
        for (int i = 0; i < candidates.size() - 1; i++)
            cout << candidates[i] << ' ';
        cout << candidates[candidates.size() - 1] << '\n';
        return;
    }

    int prev = -1;
    for (int i = pos; i < N; i++)
    {
        if (prev != numbers[i])
        {
            prev = numbers[i]; // do not put same value twice
            candidates.emplace_back(numbers[i]);
            backtrack(cnt - 1, i + 1);
            candidates.pop_back();
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    sort(numbers, numbers + 8);

    backtrack(M, 0);
}

/*
#15663과 비슷한 아이디어. prev를 잘 사용하자.
같은 자리에 같은 숫자가 다시 오는걸 막는 장치임을 기억하자.
다른 i에서 같은 숫자가 나오더라도 이미 앞 i에서 backtrack하면서
뒷쪽 i에서 나올 수 있는 모든 조합을 만들었기 때문에 무조건
중복된 수열이 만들어지게 된다.
*/