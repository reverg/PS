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