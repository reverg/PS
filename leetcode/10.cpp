class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int sl = s.size();
        int pl = p.size();

        // Create a 2D DP table initialized to false
        vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1, false));

        // Base case: both s and p are empty
        dp[sl][pl] = true;

        // Fill the DP table
        for (int i = sl; i >= 0; i--)
        {
            for (int j = pl - 1; j >= 0; j--)
            {
                bool first_match = (i < sl && (p[j] == s[i] || p[j] == '.'));

                if (j + 1 < pl && p[j + 1] == '*')
                {
                    // Case for '*': match zero or more of the preceding element
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                }
                else
                {
                    // Case for normal character or '.': match next character
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};

/*
(Runtime, Memory) = (75.05%, 32.58%)
*의 존재 때문에 앞부터 순서대로 대응시켜보며 한번에 확인하는건 불가능하다.
recursive하게 s와 p를 잘라가면서 확인하는 방법이 있긴 하지만 뒤쪽에서 발생할 수
있는 경우의 수가 굉장히 많아서 O((T+P) * 2^(T + P/2))의 시간복잡도가 나온다.
왜 이런 시간복잡도가 나오는지는 이해 못했으니 언젠가 Leetcode의 Editorial 참고.

DP를 사용하면 비교적 간단하게 풀 수 있다. dp[i][j]를 text[i:]와 pattern[j:]가
매칭되는지 여부로 두고, 뒤부터 앞으로 오면서 매칭되는지 확인한다. 각각의 (i, j)에
대해 한번씩만 확인하므로 O(len(text) * len(pattern))의 시간과 공간복잡도에 해결된다.

앞에서부터 매칭하는지 뒤에서부터 매칭하는지가 굉장히 중요한 것 같다. 인덱싱이 헷갈릴 수
있으므로 상당히 유의할 필요가 있다. 근데 솔직히 이런 문제 본 적 없는데 면접에서 풀라고
주면 풀 수 있나 싶다.
*/