class Solution
{
public:
    unordered_set<string> word_set;
    unordered_map<string, bool> dp;

    bool dfs(string &word)
    {
        if (dp.find(word) != dp.end())
            return dp[word];

        if (word.size() == 1)
        {
            dp[word] = true;
            return true;
        }
        else
        {
            string prefix = word.substr(0, word.length() - 1);
            if (word_set.find(prefix) != word_set.end())
            {
                dp[word] = dfs(prefix);
                return dp[word];
            }
            else
            {
                dp[word] = false;
                return false;
            }
        }
    }

    string longestWord(vector<string> &words)
    {
        word_set.insert(words.begin(), words.end());

        int max_len = 0;
        string ans_word = "";
        for (string word : words)
        {
            if (!dfs(word))
                continue;

            if (word.length() > max_len)
            {
                max_len = word.length();
                ans_word = word;
            }
            else if (word.length() == max_len)
            {
                if (ans_word > word)
                    ans_word = word;
            }
        }

        return ans_word;
    }
};

/*
(Runtime, Memory) = (47.31%, 70.66%). #1048과 같이 보면 좋다.
Top-down DP. 마지막 글자를 뗀 단어를 만들어서 dfs로 탐색한다.
최악의 경우엔 모든 단어를 길이 1이 될 때까지 순회하므로 O(NL).
이전에 나타난 문자열은 메모해두므로 실제 실행 횟수는 모든 최종 문자열의 길이 총합이 된다.
재귀 횟수는 min(N, L)이 되긴 하지만 map, set때문에 O(N)의 공간을 쓴다.
*/