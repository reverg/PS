#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Snowman
{
    int small;
    int big;
    int height;
};

bool cmp(Snowman s1, Snowman s2)
{
    return s1.height < s2.height;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int snow[N];
    for (int i = 0; i < N; i++)
        cin >> snow[i];

    vector<Snowman> snowmans;
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            snowmans.push_back({i, j, snow[i] + snow[j]});

    sort(snowmans.begin(), snowmans.end(), cmp);

    int ans = 2e9;
    for (int i = 0; i < snowmans.size() - 1; i++)
    {
        Snowman elsa = snowmans[i];
        for (int j = i + 1; j < snowmans.size(); j++)
        {
            Snowman anna = snowmans[j];
            int diff = anna.height - elsa.height;
            if (diff >= ans)
                break;
            if (elsa.small != anna.small && elsa.small != anna.big && elsa.big != anna.small && elsa.big != anna.big)
            {
                ans = diff;
                break;
            }
        }
    }

    cout << ans << '\n';
}

/*
가능한 눈사람 조합 모조리 만들어두고 투 포인터.
조합 만드는데 O(N^2), 정렬에 O(N^2 log(N^2)),
투 포인터 O(N^2)이므로 O(N^2 logN) 알고리즘이다.
서로 다른 눈덩이를 써야 하므로 확인 작업을 거친다.
*/