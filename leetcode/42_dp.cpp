;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;

        int left_max[height.size()];
        int right_max[height.size()];
        fill(left_max, left_max + height.size(), 0);
        fill(right_max, right_max + height.size(), 0);

        int tmp = 0;
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i - 1] > tmp)
                tmp = height[i - 1];
            left_max[i] = tmp;
        }

        tmp = 0;
        for (int i = height.size() - 2; i >= 0; i--)
        {
            if (height[i + 1] > tmp)
                tmp = height[i + 1];
            right_max[i] = tmp;
        }

        for (int i = 0; i < height.size(); i++)
        {
            int trapped = min(left_max[i], right_max[i]) - height[i];
            if (trapped > 0)
                ans += trapped;
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (75.06%, 7.08%)
각 x좌표별로 담기는 물의 양 = 자기 양 옆 벽 중 낮은거 높이 - 자기 높이
매번 양 옆을 확인하면 O(N)이지만 따로 저장해두면 O(1)에 확인되므로
전체를 O(N^2)에서 O(N)으로 줄일 수 있다. 대신 공간은 O(1)이 아니라 O(N)이다.
*/