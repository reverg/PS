class Solution
{
public:
    int countBits(int num)
    {
        int cnt = 0;
        while (num > 0)
        {
            cnt += num & 1;
            num >>= 1;
        }
        return cnt;
    }

    long long countExcellentPairs(vector<int> &nums, int k)
    {
        unordered_set<int> unique_nums(nums.begin(), nums.end());
        vector<int> bit_cnt;

        for (auto num : unique_nums)
            bit_cnt.push_back(countBits(num));

        sort(bit_cnt.begin(), bit_cnt.end());

        long long ans = 0;
        for (int i = 0; i < bit_cnt.size(); i++)
        {
            auto it = lower_bound(bit_cnt.begin(), bit_cnt.end(), k - bit_cnt[i]);
            ans += bit_cnt.end() - it;
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (53.85%, 29.30%).
x^y 1 수 + x&y 1 수 = x 1 수 + y 1 수임을 잘 찾아내면 된다.
중복은 안되지만 자기 자신을 2번 쓰는건 가능하므로 set으로 중복된 수를 걸러내고
이분 탐색을 쓰면 O(NlogN) 시간에 풀 수 있다. 공간은 O(N).
*/