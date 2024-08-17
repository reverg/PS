class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++)
        {
            for (string word : wordDict)
            {
                int word_len = word.length();
                if (i < word_len)
                    continue;

                if (dp[i - word_len] && s.substr(i - word_len, word_len) == word)
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
};

/*
(Runtime, Memory) = (100.00%, 83.00%)
DP 문제. bottom-up으로 풀었다. top-down도 가능하지만 재귀를 돌아서
개인적으론 별로다. 같은 단어를 여러 번 사용 가능하므로 벡터에 넣어두고
순회한다. 중복 사용 불가하면 set에 넣어놨다 지우면 될 듯. 각각의 위치에
대해 단어를 전부 확인하므로 O(NM)인데, substr이 문자 개수만큼 시간을 써서
최종적으로 O(NMK)의 시간에 동작한다. 공간복잡도는 dp 배열에 사용하는 O(N).
#140이 모든 가능한 문자 조합을 출력하는 강화판이니 참고.
*/