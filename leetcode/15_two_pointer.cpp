class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int jk_sum = nums[left] + nums[right];

                if (jk_sum < target)
                    left++;
                else if (jk_sum > target)
                    right--;
                else
                {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    ans.push_back(triplet);

                    while (left < right && nums[left] == triplet[1])
                        left++;
                    while (left < right && nums[right] == triplet[2])
                        right--;
                }
            }

            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (62.85%, 34.59%)
정렬 후에 투 포인터로 {i, j, k}쌍 구하기. 훨씬 직관적이고 중복 처리도 간편하다.
그렇지만 솔직히 hash로 처리하는거에 익숙해지면 잘 떠오르는 풀이는 아니다...
시간복잡도는 O(N^2), 공간은 답 저장 외에 딱히 쓰는게 없어서 O(1).
그런데도 O(N)을 쓰는 hash 풀이랑 메모리는 비슷하게 나오는데 리트코드쪽 문제인 듯.
*/