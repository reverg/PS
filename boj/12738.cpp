#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        if (v.empty() || num > v.back())
            v.emplace_back(num);
        else
        {
            int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[idx] = num;
        }
    }

    cout << v.size() << '\n';
}

/*
#12015에서 범위 늘어난 것. 트래킹이 추가되면 #14003이 된다.
새로운 수가 벡터의 마지막 수보다 크면 지금까지 중 가장 큰 수이므로
맨 뒤에 집어넣는다. 아니면 lower_bound로 새로운 값 이상인 가장 작은 수
위치에 집어넣어준다. 새로운 수를 넣어도 순서가 계속 유지되어야 하는게
중요하고, 이 방식이 가장 인덱스 문제 없이 무난하다. 최종 벡터는 LIS는
아니지만 길이는 LIS와 같다. 시간은 lower_bound가 O(logN)이므로 O(NlogN).
*/