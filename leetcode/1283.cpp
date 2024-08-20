class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());

        while (lo <= hi) {
            int divisor = (lo + hi) / 2;
            int sum_by_divisor = 0;
            for (int num : nums)
                sum_by_divisor += (num + divisor - 1) / divisor;

            if (sum_by_divisor <= threshold)
                hi = divisor - 1;
            else
                lo = divisor + 1;
        }

        return lo;
    }
};

/*
(Runtime, Memory) = (83.93%, 56.56%).
이분탐색 구현. 늘 사람을 미치게 하는 유형이다.
매번 그렇듯이 무한루프 안 걸리게 유의.
*/