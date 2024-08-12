#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> numbers;
vector<int> seq;

void backtrack(int cnt, int pos)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << seq[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = pos; i < numbers.size(); i++)
    {
        seq.emplace_back(numbers[i]);
        backtrack(cnt + 1, i);
        seq.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        numbers.emplace_back(num);
    }

    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    backtrack(0, 0);
}

/*
#15657에 중복된 숫자가 가능하다는 조건만 추가되었다.
같은 수를 여러 번 골라도 되므로 중복을 제거해준 자연수 리스트 내에서 고르면 된다.
43~44행의 중복 제거 코드를 기억해두자. 반드시 정렬된 후에 44행을 실행해야 한다.
*/