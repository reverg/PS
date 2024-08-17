class Solution
{
public:
    vector<string> ans;
    unordered_set<string> wordSet;
    vector<string> wordParts;

    void backtrackWord(string &s, int pos)
    {
        if (pos == s.size())
        {
            string res = "";
            for (int i = 0; i < wordParts.size() - 1; i++)
            {
                res += wordParts[i];
                res += " ";
            }
            res += wordParts[wordParts.size() - 1];
            ans.push_back(res);
        }

        for (int i = pos + 1; i <= s.size(); i++)
        {
            string sp = s.substr(pos, i - pos);
            if (wordSet.find(sp) == wordSet.end())
                continue;

            wordParts.push_back(sp);
            backtrackWord(s, i);
            wordParts.pop_back();
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (string word : wordDict)
            wordSet.insert(word);

        backtrackWord(s, 0);

        return ans;
    }
};
/*
(Runtime, Memory) = (33.35%, 63.07%)
Backtracking을 사용한 풀이.
#139때와 다르게 모든 조합을 찾아야 하므로 2^N개의 가능한 분할 방식을
모두 확인해봐야 한다. 각각의 조합에서 substr을 호출하는데, substr의
시간복잡도는 문자의 길이와 같고 모든 substr 부분의 총합은 문자열 전체이므로
합쳐서 O(N)이 된다. 따라서 시간복잡도는 O(N * 2^N)이다.
공간은 O(2^N)인데 답이 2^N개가 가능하기 때문이다... 재귀 자체는 기껏해야
N번까지밖에 안 들어가서 많은 공간을 쓰지 않는다.

DP를 사용해서 substr을 저장하면 constant를 줄이는데 도움이 되긴 하지만
모든 2^N가지를 확인해야 한다는 점에는 변함이 없으므로 시간복잡도는 동일하다.
DP 테이블에 최대 길이 N인 2^N개 substr을 저장해야 하므로 공간복잡도는
O(N * 2^N)으로 악화된다.
*/