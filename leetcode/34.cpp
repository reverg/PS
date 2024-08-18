class Solution
{
public:
    int lower_bound(vector<int> &nums, int target)
    {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return lo;
    }

    int upper_bound(vector<int> &nums, int target)
    {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (nums[mid] <= target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return lo;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int idx1 = lower_bound(nums, target);
        int idx2 = upper_bound(nums, target);

        if (idx1 == nums.size() || nums[idx1] != target)
            return {-1, -1};
        else
            return {idx1, idx2 - 1};
    }
};

/*
(Runtime, Memory) = (100.00%, 61.88%).
lower_bound와 upper_bound를 직접 구현하면 되는 문제. 그냥 외워두는게 속 편하다.
12~15행과 29~32행이 자주 헷갈리는데 lo랑 hi랑 1 차이나는 상황으로 테스트하면
무한루프에 빠지는걸 막는데 도움이 된다. 연습 삼아서 둘 다 구현하긴 했지만
따로 upper_bound 구현 안하고 lower_bound에서 target+1로 찾는 것도 가능하다.

STL로 날먹해도 된다. 마지막 if문을 잘 기억해둘 것. lower_bound가 못 찾거나
찾은게 target 값이 아니면 target이 안에 없단 것이므로 예외로 처리 해줘야 한다.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower_it = lower_bound(nums.begin(), nums.end(), target);
        auto upper_it = upper_bound(nums.begin(), nums.end(), target);

        if(lower_it == nums.end() || *lower_it != target)
            return {-1, -1};
        else
            return {(int)(lower_it - nums.begin()), (int)(upper_it - nums.begin() - 1)};
    }
};
*/