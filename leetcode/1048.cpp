class Solution
{
public:
    static bool cmp(const string &s1, const string &s2)
    {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string> &words)
    {
        unordered_map<string, int> dp;

        sort(words.begin(), words.end(), cmp); // O(NlogN)

        int ans = 1;
        for (string w : words)
        {
            int cur_seq_len = 1;
            for (int i = 0; i < w.length(); i++)
            {
                string predecessor = w.substr(0, i) + w.substr(i + 1); // O(L)
                if (dp.find(predecessor) != dp.end())
                {
                    int prev_seq_len = dp[predecessor];
                    cur_seq_len = max(cur_seq_len, prev_seq_len + 1);
                }
            }
            dp[w] = cur_seq_len;
            ans = max(ans, cur_seq_len);
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (82.27%, 48.71%). #720과 같이 보면 좋다.
Bottom-up DP. 처음에는 a-z를 1개씩 끼워넣어서 다음 단어를 만들어야겠다고
생각했는데 글자 1개를 지워서 이전 단어를 만드는게 훨씬 효율적이다.
Sorting이 O(NlogN), 16~30행의 루프가 O(N * L * L)이라 전체는 O(N(logN + L^2)).

Top-down DP는 sorting이 없어서 O(N L^2)에 된다. #720은 top-down으로 풀었다.
공간복잡도는 둘 다 O(N). map이나 set에 저장되는 string byte는 O(NL)이긴 한데
string만 저장하는건 아니라서 그냥 O(N)으로 쓰는게 맞는 것 같다.
아래의 코드는 top-down DP 풀이.

class Solution {

private:

    int dfs(unordered_set<string> &words, unordered_map<string, int> &memo, string currentWord) {
        // If the word is encountered previously we just return its value present in the map (memoization).
        if (memo.find(currentWord) != memo.end()) {
            return memo[currentWord];
        }
        // This stores the maximum length of word sequence possible with the 'currentWord' as the
        int maxLength = 1;

        // creating all possible strings taking out one character at a time from the `currentWord`
        for (int i = 0; i < currentWord.length(); i++) {
            string newWord = currentWord.substr(0, i) + currentWord.substr(i + 1);
            // If the new word formed is present in the list, we do a dfs search with this newWord.
            if (words.find(newWord) != words.end()) {
                int currentLength = 1 + dfs(words, memo, newWord);
                maxLength = max(maxLength, currentLength);
            }
        }
        memo[currentWord] = maxLength;

        return maxLength;
    }

public :
    int longestStrChain(vector<string> &words) {
        unordered_map<string, int> memo;
        unordered_set<string> wordsPresent;
        for (const string &word : words) {
            wordsPresent.insert(word);
        }
        int ans = 0;
        for (const string &word : words) {
            ans = max(ans, dfs(wordsPresent, memo, word));
        }
        return ans;
    }
};
*/