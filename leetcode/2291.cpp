class Solution
{
public:
    int maximumProfit(vector<int> &present, vector<int> &future, int budget)
    {
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < present.size(); i++)
            for (int j = budget; j >= present[i]; j--)
                if (future[i] > present[i])
                    dp[j] = max(dp[j], (future[i] - present[i]) + dp[j - present[i]]);

        return dp[budget];
    }
};

/*
(Runtime, Memory) = (85.71%, 83.46%)
knapsack 문제다.
1차원 배열로 풀었는데 이에 관해서는 백준에서 푼 냅색 문제 참고.
시간복잡도는 O(NM), 공간복잡도는 O(N).
*/