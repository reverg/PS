class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;

        for (int i = 0; i < (int)nums.size(); i++) {
            int c = target - nums[i];
            if (um.count(c)) {
                return {um[c], i};
            }
            um[nums[i]] = i;
        }

        return {};
    }
};

/*
#1 -> #454 -> #15 -> #18로 이어진다.
brute force로 다 확인하면 O(N^2), 정렬하고 two pointer나
binary search 쓰면 O(NlogN), hash table에 넣으면 O(N).
*/