class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxElem = *max_element(nums.begin(), nums.end());
        long long ans = 0;

        int start = 0;
        for (int end = 0; end < nums.size(); end++)
        {
            if (nums[end] == maxElem)
                k--;

            while (k == 0)
            {
                if (nums[start] == maxElem)
                    k++;

                start++;
            }

            ans += start;
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (77.49%, 56.18%).
start와 end 사이에 딱 k개의 최대값이 오도록 조정하면 0~end부터
start~end까지의 모든 구간이 조건을 만족한다. 시간 O(N), 공간 O(1).
*/