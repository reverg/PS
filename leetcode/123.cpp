class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int left_min = prices[0];
        int right_max = prices[prices.size() - 1];

        vector<int> left_profit(prices.size(), 0);
        for (int i = 1; i < prices.size(); i++)
        {
            left_profit[i] = max(left_profit[i - 1], prices[i] - left_min);
            if (left_min > prices[i])
                left_min = prices[i];
        }

        vector<int> right_profit(prices.size() + 1, 0);
        for (int i = prices.size() - 2; i >= 0; i--)
        {
            right_profit[i] = max(right_profit[i + 1], right_max - prices[i]);
            if (right_max < prices[i])
                right_max = prices[i];
        }

        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (max_profit < left_profit[i] + right_profit[i + 1])
                max_profit = left_profit[i] + right_profit[i + 1];
        }

        return max_profit;
    }
};

/*
(Runtime, Memory) = (95.75%, 73.33%). #121 -> #122 -> #123 -> #188.
딱 2번 사고 팔 수 있다. 무조건 판 후에 다시 살 수 있으므로 구간을 반반 갈라서 생각하면 된다.
121번 같은 느낌으로 0~i에서 최대 이득을 보는 left_profit, i~N에서 최대 이득을 보는 right_profit으로
나눠서 따로 dp를 돌리고 어떻게 구간을 나누는게 가장 이득을 많이 볼 수 있는지 확인하면 된다.
배열 순회만 3번 하므로 시간복잡도는 O(N)이고, 추가로 사용하는 배열도 공간복잡도 O(N)이다.

2번에 나눠 사는 과정을 잘 쪼개서 추가 공간 없이 푸는 방법도 있다. 시간 O(N), 공간 O(1).
t2_min이 price-t1_profit이라 1번 사기 전까지는 갱신이 안 되는데 이런걸 어떻게 생각하나 싶다...
직전 거래에서 이득 본 만큼을 이번 거래에 녹여서 이번 주식을 그만큼 더 싸게 사서 차액을 남긴다는
느낌으로 생각하면 좀 이해가 편하다.

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int t1_min = INT_MAX,
            t2_min = INT_MAX;
        int t1_profit = 0,
            t2_profit = 0;

        for (int price : prices)
        {
            // the maximum profit if only one transaction is allowed
            t1_min = min(t1_min, price);
            t1_profit = max(t1_profit, price - t1_min);

            // re-invest profit in second transaction
            t2_min = min(t2_min, price - t1_profit);
            t2_profit = max(t2_profit, price - t2_min);
        }

        return t2_profit;
    }
};
*/