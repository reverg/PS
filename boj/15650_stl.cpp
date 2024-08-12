#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> selected_nums;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        numbers.push_back(i);
    for (int i = 1; i <= M; i++)
        selected_nums.push_back(0);
    for (int i = M + 1; i <= N; i++)
        selected_nums.push_back(1);

    do
    {
        for (int i = 0; i < N; i++)
            if (!selected_nums[i])
                cout << numbers[i] << ' ';
        cout << '\n';
    } while (next_permutation(selected_nums.begin(), selected_nums.end()));
}

/*
next_permutation을 활용한 풀이. 15649는 내부에서 순서가 바뀔 수 있으므로
이런 방식을 사용하긴 좀 애매하다. 시험삼아서 풀어보긴 했는데 시험 상황에서는
그냥 backtracking을 쓰는게 훨씬 실수가 적을만한 풀이인 듯.
*/