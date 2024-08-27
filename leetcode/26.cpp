class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return unique(nums.begin(), nums.end()) - nums.begin();
    }
};

/*
(Runtime, Memory) = (100.00%, 16.14%). 편차가 커서 의미는 없음.
STL은 신이다. unique가 iterator를 반환함을 기억해두자.

포인터 2개로 중복 자리에 덮어쓰는 정석 풀이는 아래 참고:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIndex = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] != nums[i]) {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }
        return insertIndex;
    }
};
*/