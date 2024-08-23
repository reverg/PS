class Solution
{
public:
    void backtrack(int cur_sum, int cur_idx, vector<int> &candidates,
                   vector<int> &stat_vec, vector<vector<int>> &ans,
                   int target)
    {
        if (cur_sum == target)
        {
            vector<int> comb;
            for (int i = 0; i < stat_vec.size(); i++)
                for (int j = 0; j < stat_vec[i]; j++)
                    comb.push_back(candidates[i]);
            ans.push_back(comb);
        }
        if (cur_sum >= target || cur_idx == candidates.size())
            return;

        int cur_num = candidates[cur_idx];
        int max_add = (target - cur_sum) / cur_num;

        for (int i = 0; i <= max_add; i++)
        {
            stat_vec[cur_idx] = i;
            int next_sum = cur_sum + cur_num * i;
            backtrack(next_sum, cur_idx + 1, candidates, stat_vec, ans, target);
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());

        vector<int> stat_vec(candidates.size(), 0);
        backtrack(0, 0, candidates, stat_vec, ans, target);

        return ans;
    }
};

/*
(Runtime, Memory) = (79.22%, 42.27%).
backtracking으로 다 해보는 풀이. 같은 동전을 여러 번 쓰는게 가능하므로
bottom-up DP를 쓰는 풀이도 가능하다. 다만 target이 작고 모든 조합을 다
출력해야 하는 문제여서 DP가 실제 실행시간상으로 도움이 되진 않는다.
backtrack 풀이는 시간 O(2^N), 공간은 O(N). DP는 시간 O(target * N^2),
공간 O(target * N)이다. 아래 코드 참고.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        unordered_map<int, vector<vector<int>>> dp;
        dp[0] = {{}};

        for (int i : nums){
            for (int j = i; j <= target; j++){
                for (auto v : dp[j - i]){
                    v.push_back(i);
                    dp[j].push_back(v);
                }
            }
        }


        return dp[target];
    }
};
*/