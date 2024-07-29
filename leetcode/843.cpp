/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

int getSimillarity(string &a, const string &b)
{
    int cnt = 0;
    for (int i = 0; i < 6; i++)
        if (a[i] == b[i])
            cnt++;

    return cnt;
}

class Solution
{
public:
    void findSecretWord(vector<string> &words, Master &master)
    {
        unordered_set<string> us(words.begin(), words.end());
        while (true)
        {
            string guess_word = *us.begin();
            int guess_sim = master.guess(guess_word);
            if (guess_sim == 6)
                break;
            for (auto it = us.begin(); it != us.end();)
            {
                if (getSimillarity(guess_word, *it) != guess_sim)
                {
                    it = us.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }
    }
};

/*
내가 알고 있는 단어들 중에 답이 있으므로, guess한 단어와 비교했을 때 유사도가
결과값이랑 안 맞는 것들은 모조리 없애주면 된다. 자기 자신은 유사도가 6이 나오므로
항상 맨 앞의 단어를 골라서 guess해도 같은 단어를 guess할 일은 없다.
*/