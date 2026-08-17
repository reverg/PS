class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[word1.size() + 1][word2.size() + 1];

        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] =
                        min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

/*
(Runtime, Memory) = (71.67%, 86.09%)
LCS 변형 문제. 처음에는 긴 단어 길이 - LCS 길이 하면 될 줄 알았는데
반례가 있어서 안된다. 시간, 공간 모두 O(MN).
*/