class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_price = 10000;
        int max_profit = 0;

        for (int price : prices)
        {
            if (price < min_price)
                min_price = price;
            else if (price - min_price > max_profit)
                max_profit = price - min_price;
        }

        return max_profit;
    }
};

/*
(Runtime, Memory) = (64.61%, 16.98%). #121 -> #122 -> #123 -> #188.
브루트포스로 다 하면 O(N^2)라 한세월 걸린다.
이전까지의 최소값과 현재 값의 차이가 최대인 경우가 최대 이익이므로
min_price만 따로 관리해주며 최대 이익을 업데이트 해주면 된다.
*/