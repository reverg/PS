class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int lo = 0;
        int hi = m * n - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int cur_num = matrix[mid / n][mid % n];

            if (cur_num == target)
                return true;
            else if (cur_num < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return false;
    }
};

/*
(Runtime, Memory) = (100.00%, 26.87%), #74 -> #240
Binary search 문제. 아쉽게도 2차원 배열을 벡터로 바꾸려면 O(MN)이 들거라
lower_bound로 날먹 못하고 직접 짜야 한다. 문제는 어렵지 않지만 lo, hi, mid
조정에 주의. 잘못 구현하면 무한루프에 빠진다. lo + 1 = hi인 경우를 체크해보면 좋다.
*/