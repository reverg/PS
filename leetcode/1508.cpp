class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        int subarr_sums[n * (n + 1) / 2];
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            int sub_sum = 0;
            for (int j = i; j < n; j++)
            {
                sub_sum += nums[j];
                subarr_sums[k++] = sub_sum;
            }
        }

        sort(subarr_sums, subarr_sums + n * (n + 1) / 2);

        int ans = 0;
        const int mod = 1e9 + 7;
        for (int i = left - 1; i < right; i++)
            ans = (ans + subarr_sums[i]) % mod;

        return ans;
    }
};

/*
(Runtime, Memory) = (77.75%, 75.95%)
뭔가 대단한 풀이 방법이 있을 것도 같지만 놀랍게도 그냥 하는거다...
nums[i]가 100 이하, n이 1000 이하라 구간합이 커봐야 10만, 개수가
커봐야 50만 정도인게 핵심. 이 정도면 O(N^2logN)으로 충분히 처리된다.

다른 풀이로 priority queue를 사용하는 것도 있다. 시간복잡도는 똑같으나
공간복잡도가 O(N)인게 이점이다. (구간 합, 구간의 마지막 인덱스)를 넣는
pq를 사용한다. 처음에 구간 1짜리를 다 만들어서 넣고, pop하고, 구간을
1개 더 늘려서 새로운 합을 만들고 pq에 넣는걸 반복하자. 그러면 가장 작은
구간 합은 무조건 구간 1짜리에 있고, 구간이 늘어날수록 합은 단조증가하므로
pq를 계속 pop하면 작은 구간 합부터 순서대로 나온다.

binary search 풀이도 가능하다. 시간 O(N log(sum)), 공간 O(1).
edtorial 풀이 봐도 잘 모르겠어서 복붙해둠. 언젠간 이해하겠지...?

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        long result =
            (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) %
            mod;
        // Ensure non-negative result
        return (result + mod) % mod;
    }

private:
    int mod = 1e9 + 7;
    // Helper function to count subarrays with sum <= target and their total sum.
    pair<int, long long> countAndSum(vector<int> &nums, int n, int target)
    {
        int count = 0;
        long long currentSum = 0, totalSum = 0, windowSum = 0;
        for (int j = 0, i = 0; j < n; ++j)
        {
            currentSum += nums[j];
            windowSum += nums[j] * (j - i + 1);
            while (currentSum > target)
            {
                windowSum -= currentSum;
                currentSum -= nums[i++];
            }
            count += j - i + 1;
            totalSum += windowSum;
        }
        return {count, totalSum};
    }

    // Helper function to find the sum of the first k smallest subarray sums.
    long long sumOfFirstK(vector<int> &nums, int n, int k)
    {
        int minSum = *min_element(nums.begin(), nums.end());
        int maxSum = accumulate(nums.begin(), nums.end(), 0);
        int left = minSum, right = maxSum;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (countAndSum(nums, n, mid).first >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        auto [count, sum] = countAndSum(nums, n, left);
        // There can be more subarrays with the same sum of left.
        return sum - left * (count - k);
    }
};
*/