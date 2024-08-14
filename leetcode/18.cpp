class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }

    vector<vector<int>> kSum(vector<int> &nums, long long target, int start, int k)
    {
        vector<vector<int>> res;

        // base case
        if (k == 1)
        {
            if (nums[start] == k)
                return {{nums[start]}};
            else
                return res;
        }
        if (k == 2)
            return twoSum_twoptr(nums, target, start);

        // 끝까지 오면 빈 벡터 반환
        if (start == nums.size())
            return res;

        // optimization: 정렬된 수에서 찾으므로 평균값보다 시작 수가 크면 합은 무조건 목표보다 커짐
        long long avg_val = target / k;
        if (nums[start] > avg_val || avg_val > nums.back())
            return res;

        for (int i = start; i < nums.size(); i++)
        {
            if (i == start || nums[i - 1] != nums[i])
            {
                for (vector<int> &subset : kSum(nums, (long long)target - nums[i], i + 1, k - 1))
                {
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(subset), end(subset));
                }
            }
        }

        return res;
    }

    vector<vector<int>> twoSum_twoptr(vector<int> &nums, long long target, int start)
    {
        vector<vector<int>> res;
        int lo = start, hi = int(nums.size()) - 1;

        while (lo < hi)
        {
            int cur_sum = nums[lo] + nums[hi];
            if (cur_sum < target || (lo > start && nums[lo] == nums[lo - 1]))
                lo++;
            else if (cur_sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
                hi--;
            else
                res.push_back({nums[lo++], nums[hi--]});
        }

        return res;
    }

    vector<vector<int>> twoSum_hash(vector<int> &nums, long long target, int start)
    {
        vector<vector<int>> res;
        unordered_set<long long> s;

        for (int i = start; i < nums.size(); ++i)
        {
            if (res.empty() || res.back()[1] != nums[i])
                if (s.count(target - nums[i]))
                    res.push_back({int(target - nums[i]), nums[i]});

            s.insert(nums[i]);
        }

        return res;
    }
};

/*
Two pointer -> (Runtime, Memory) = (99.51%, 25.07%)
Hash -> (Runtime, Memory) = (25.98%, 36.30%)

말만 four sum이고 사실상 k sum 문제가 되어버렸다. 사용된 4개 수의 index가 모두
달라야 해서 머리가 아픈데 재귀적으로 (target - 수 1개)를 (k-1) sum으로 만드는 방식을
써서 처리했다. 투 포인터와 해시 중 하나를 이용해서 two sum을 O(1)에 처리 가능하고,
k가 1 늘어날 때마다 O(N)이 곱해지므로 k sum의 시간복잡도는 O(N^(k-1))이 된다.
recursion을 위한 공간이 필요하므로 hash를 안 써도 O(N)의 공간복잡도가 된다.

40~41행의 벡터 생성, 57, 59, 75행의 중복 처리 방법을 확인하자. 추가적으로 3Sum(#15)의
hash 풀이에 다른 방법으로 시도했다가 처참히 실패한 기록도 보면 좋다.
*/