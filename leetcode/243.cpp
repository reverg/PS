class Solution
{
public:
    int shortestDistance(vector<string> &wordsDict, string word1, string word2)
    {
        int word1_pos = -1;
        int word2_pos = -1;
        int min_dist = wordsDict.size();

        for (int i = 0; i < wordsDict.size(); i++)
        {
            bool updated = false;
            if (wordsDict[i] == word1)
            {
                word1_pos = i;
                updated = true;
            }
            else if (wordsDict[i] == word2)
            {
                word2_pos = i;
                updated = true;
            }

            if (updated && word1_pos != -1 && word2_pos != -1)
            {
                int cur_dist = abs(word1_pos - word2_pos);
                if (min_dist > cur_dist)
                    min_dist = cur_dist;
            }
        }

        return min_dist;
    }
};

/*
(Runtime, Memory) = (82.62%, 28.21%).
one-pass로 가능. string 비교에 O(L) 걸리니까 시간은 O(NL), 공간은 따로 안써서 O(1).
*/