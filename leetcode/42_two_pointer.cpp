class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= left_max)
                    left_max = height[left];
                else
                    ans += (left_max - height[left]);
                left++;
            }
            else
            {
                if (height[right] >= right_max)
                    right_max = height[right];
                else
                    ans += (right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
};

/*
(Runtime, Memory) = (88.39%, 9.95%)
dp 풀이와 아이디어가 비슷한데, 어차피 왼쪽/오른쪽 최대 높이는 오른쪽/왼쪽으로
갈 수록 커지므로 굳이 다 저장해둘 필요가 없고 투 포인터로 처리 가능하다.
시간복잡도는 똑같이 O(N)이지만 공간복잡도를 O(1)으로 줄일 수 있다.
*/