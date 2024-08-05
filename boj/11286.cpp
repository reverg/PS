#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<int, vector<int>, compare> pq;

struct compare
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        else
            return abs(a) > abs(b);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (num != 0)
            pq.push(num);
        else
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
                continue;
            }

            cout << pq.top() << '\n';
            pq.pop();
        }
    }
}

/*
priority_queue는 container가 들어가서 함수인 sort때와
comp 정의 부분이 좀 다르다. comp(a, a) = false여야 런타임
에러가 나지 않음을 명심하자.
*/