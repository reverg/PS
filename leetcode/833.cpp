class Solution
{
public:
    string findReplaceString(string s, vector<int> &indices, vector<string> &sources, vector<string> &targets)
    {
        map<int, pair<string, string>> replace_hash;
        for (int i = 0; i < indices.size(); i++)
        {
            if (s.substr(indices[i], sources[i].size()) == sources[i])
                replace_hash[indices[i]] = {sources[i], targets[i]};
        }

        int pos = 0;
        string res = "";
        while (pos < s.size())
        {
            if (replace_hash.find(pos) != replace_hash.end())
            {
                res += replace_hash[pos].second;
                pos += replace_hash[pos].first.size();
            }
            else
            {
                res += s[pos];
                pos++;
            }
        }

        return res;
    }
};

/*
(Runtime, Memory) = (33.97%, 36.04%)
일치했던 부분을 따로 저장해놨다가 원본 string의 앞부터 순서대로 바꿔준다.
9행에서 substr 안쓰고 직접 index로 비교하면 더 빠름. (Runtime 100%)
*/