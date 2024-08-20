class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        long long max_subarray_sum = 0;

        unordered_map<int, int> counter;
        int distinct_numbers = 0;

        long long subarray_sum = 0;
        for (int i = 0; i < k; i++)
        {
            counter[nums[i]]++;
            if (counter[nums[i]] == 1)
                distinct_numbers++;

            subarray_sum += nums[i];
        }

        if (distinct_numbers >= m)
            max_subarray_sum = subarray_sum;

        for (int i = k; i < nums.size(); i++)
        {
            counter[nums[i - k]]--;
            if (counter[nums[i - k]] == 0)
                distinct_numbers--;

            counter[nums[i]]++;
            if (counter[nums[i]] == 1)
                distinct_numbers++;

            subarray_sum -= nums[i - k];
            subarray_sum += nums[i];

            if (distinct_numbers >= m)
            {
                if (max_subarray_sum < subarray_sum)
                    max_subarray_sum = subarray_sum;
            }
        }

        return max_subarray_sum;
    }
};

/*
(Runtime, Memory) = (65.77%, 41.44%).
sliding window + counting using map.
*/