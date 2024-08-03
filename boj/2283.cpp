#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int max_end = 0;
    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;
        arr.push_back({s, 1});
        arr.push_back({e, -1});
        max_end = max(max_end, e);
    }

    sort(arr.begin(), arr.end());

    int len_sum = 0;
    int left = 0, right = 0;
    int leftIdx = 0, rightIdx = 0;
    int leftCnt = 0, rightCnt = 0;

    while (len_sum != K)
    {
        if (len_sum < K)
        {
            if (right == max_end)
            {
                left = 0;
                right = 0;
                break;
            }
            else
            {
                while (arr[rightIdx].first <= right)
                {
                    rightCnt += arr[rightIdx].second;
                    rightIdx++;
                }

                right++;
                len_sum += rightCnt;
            }
        }
        else
        {
            while (arr[leftIdx].first <= left)
            {
                leftCnt += arr[leftIdx].second;
                leftIdx++;
            }

            left++;
            len_sum -= leftCnt;
        }
    }

    cout << left << ' ' << right << '\n';
}

/*
막대가 어디부터 어디까지인지는 필요 없고, 시작점들과
끝점들만 알면 구간 안에 몇 개의 막대가 들어와 있는지
알 수 있다. 구간 길이를 L이라 하면 구간에 대해서
투 포인터를 쓰며 시작점/끝점 정보를 체크할 때 O(L),
과정 중 점들 정보도 모두 2번씩만(포함/배제) 확인하므로
O(L+N) 알고리즘이다. 막대가 아니라 점 정보만 알면 되는게
핵심이다. (시작점, 끝점)으로 확인하려면 꽤나 복잡해진다.
*/