class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int profit[k + 1];
        int cost[k + 1];
        fill(profit, profit + k + 1, 0);
        fill(cost, cost + k + 1, 1e8);

        for (int price : prices)
        {
            for (int i = 1; i <= k; i++)
            {
                cost[i] = min(cost[i], price - profit[i - 1]);
                profit[i] = max(profit[i], price - cost[i]);
            }
        }

        return profit[k];
    }
};

/*
(Runtime, Memory) = (100.00%, 88.47%)
#123을 k번으로 확장하면 된다. cost[i]와 profit[i]는 각각 i번째 거래에서의
매입 단가와 i번째 거래 후 번 총 수익이다. 이번 거래에 직전까지 번 이득을
녹이면 이번 주식을 그만큼 더 싸게 사서 판다고 생각할 수 있고, 이전 거래가 없으면
원가에 사서 팔게 된다. 전에 i번 거래했을 때 매입 단가와 아직 i-1번밖에 거래를 안 했고
오늘 i번째 거래를 할 때의 매입 단가를 비교해 싼 것을 선택해 i번째 거래를 진행한다(15행).
i번째까지 최대 거래 수익 합은 이전 기록과 오늘의 단가로 i번째 거래를 할 때 중 큰 것(16행).
직전 거래들에서 번 만큼 이번 주식을 싸게 샀다고 생각하는 방법을 기억해두면 좋을 것 같다.
시간복잡도는 O(NK), 공간복잡도는 O(K).
#121 -> #122 -> #123 -> #188로 이어짐.

3차원 dp의 극단적인 압축 버전이라고 볼 수도 있을 것 같다. 사용하는 dp 배열은
dp[day_number][used_transaction_number][stock_holding_status] 형태다.
코드는 아래 참고. 시간복잡도는 거래 횟수가 충분한 경우(50~57행) O(N), 아니면 O(NK).
공간복잡도는 현재 코드는 O(NK)이지만 72행의 i가 계속 증가함을 활용하면 O(K)로 압축 가능하다.

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // Solve special cases
        if (n <= 0 || k <= 0) {
            return 0;
        }

        // 거래 횟수가 충분하면 #122와 동일
        if (k * 2 >= n) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                res += max(0, prices[i] - prices[i - 1]);
            }
            return res;
        }

        // dp[i][used_k][is_hold] = balance
        // is_hold: 0 not_hold, 1 hold
        int dp[n][k+1][2];

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++)
                fill(dp[i][j], dp[i][j] + 2, INT_MIN / 2); // to prevent overflow

        // base conditions
        dp[0][0][0] = 0;
        dp[0][1][1] = -prices[0];

        // DP
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                // transition equation
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);

                // you can't hold stock without any transaction
                if (j > 0)
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        int res = 0;
        for (int j = 0; j <= k; j++)
            res = max(res, dp[n - 1][j][0]);

        return res;
    }
};
*/