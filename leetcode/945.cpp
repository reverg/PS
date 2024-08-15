class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int ans = 0;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                ans += (nums[i - 1] + 1) - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (55.83%, 30.28%)
정렬하고 앞부터 뒤로 가면서 1씩 차이나는 배열이 되게 조작한다.
시간복잡도는 정렬이 들어가서 O(NlogN), 공간복잡도는 C++의 경우
퀵/힙/삽입 정렬을 섞어 써서 O(logN)이라고 한다.
정렬하기 싫으면 N + max_val개짜리 카운터 배열을 만들고 비슷한
느낌으로 카운트가 1이 남게 뒤로 계속 넘기는 방법도 있다.
정렬은 인덱스, 카운터는 숫자를 기준으로 넘어가는 느낌이라고 보면 될 듯.
카운터 쓰면 시간, 공간복잡도 모두 O(N + max_val)이다.
*/