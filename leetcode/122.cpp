class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] < prices[i + 1])
                profit += prices[i + 1] - prices[i];
        }

        return profit;
    }
};

/*
(Runtime, Memory) = (100.00%, 42.45%). #121 -> #122 -> #123 -> #188.
내일 가격이 오늘 가격보다 높으면 오늘 사서 내일 팔고, 아니면 안 사면 된다.
계단식으로 매일 오르면 어차피 매번 팔고 다시 사므로 상승분을 다 먹을 수 있고,
다음날 떨어지는 경우는 오늘 안 사고 다음날 저점매수 하는게 더 이득이다.
prices를 처음부터 끝까지 1번 훑으므로 시간 O(N), 추가 공간 안 쓰므로 공간 O(1).
*/