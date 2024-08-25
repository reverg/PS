class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        int n = energy.size();

        vector<int> dp(n, INT_MIN);
        dp[n - 1] = energy[n - 1];

        int ans = dp[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = energy[i] + (i + k < n ? dp[i + k] : 0);
            if (dp[i] > ans)
                ans = dp[i];
        }
        return ans;
    }
};

/*
(Runtime, Memory) = (91.86%, 24.42%).
문제 이해하느라 한참 걸렸다. 진짜 간단한 DP문제.
*/