class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int prev_one_idx = -(k + 1);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (i - prev_one_idx - 1 < k)
                    return false;

                prev_one_idx = i;
            }
        }

        return true;
    }
};

/*
(Runtime, Memory) = (55.01%, 69.58%). 큰 의미는 없다.
그냥 O(N)으로 배열 쭉 훑으면 끝나는 문제. 시간 O(N), 공간 O(1)이다.
모든 원소를 1번씩은 확인해야 하므로 O(N)보다 빠르게는 불가능하다.
*/