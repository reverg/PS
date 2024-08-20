class Solution
{
public:
    int diff = INT_MAX;
    int ans = INT_MAX;

    void backtrack(vector<int> &toppingCosts, int curCost, int toppingIdx, int target)
    {
        if (abs(curCost - target) < diff)
        {
            diff = abs(curCost - target);
            ans = curCost;
        }
        else if (abs(curCost - target) == diff)
            ans = min(curCost, ans);

        if (toppingIdx >= toppingCosts.size() || curCost - target > diff)
            return;

        backtrack(toppingCosts, curCost, toppingIdx + 1, target);
        backtrack(toppingCosts, curCost + toppingCosts[toppingIdx], toppingIdx + 1, target);
        backtrack(toppingCosts, curCost + 2 * toppingCosts[toppingIdx], toppingIdx + 1, target);
    }

    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
    {
        for (auto base : baseCosts)
            backtrack(toppingCosts, base, 0, target);

        return ans;
    }
};

/*
(Runtime, Memory) = (93.25%, 45.00%).
토핑 0/1/2개 넣는걸 다 저장해두면 항상 공간을 O(3^M) 먹게 된다.
어차피 베이스별로 토핑 다 확인해봐야 할 거 backtrack을 써서 공간이라도
줄이는게 낫다. 최악의 경우에 시간 O(N * 3^M), 공간은 끝까지 재귀가
들어가면 O(3^M)이라 좋지 못하지만 실제로 일어날 확률은 낮다.
diff 따로 안 써도 되지만 쓰면 확실히 빨라진다.
*/