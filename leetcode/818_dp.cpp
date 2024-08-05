class Solution
{
public:
    int racecar(int target)
    {
        vector<int> dp(target + 1, INT_MAX);
        int p = 0;
        for (int i = 0; i <= target; i++)
        {
            if (i == (1 << p) - 1)
            {
                dp[i] = p;
                p++;
                continue;
            }

            int low = (1 << (p - 1)) - 1;
            int high = (1 << p) - 1;

            for (int j = 0; j < p; j++)
            {
                int part = (1 << j) - 1;
                int move = i - (low - part);
                // low만큼 가고 방향전환, part만큼 가고 다시 전환, 남은 만큼 가기
                dp[i] = min(dp[i], (p - 1) + 1 + j + 1 + dp[move]);
            }

            // high만큼 가고 방향전환해서 high-i만큼 반대로 가기
            dp[i] = min(dp[i], p + 1 + dp[high - i]);
        }

        return dp[target];
    }
};

/*
(Runtime, Memory) = (69.31%, 84.98%)
DP 풀이. target을 넘어가버리고 뒤로 가거나(high), target 전에서 꺾은 뒤
필요한 만큼 가서 target까지 다시 가거나(low) 2가지 방법 중 최소인 것을 택한다.
상당히 비직관적이라 BFS가 나은듯. dp 벡터도 high가 target 이상이어서 이상한
값이 나오기 딱 좋은 상황인데 일단 작동은 한다...
*/