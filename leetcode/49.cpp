class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> anagram_map;
        int count[26];
        for (string str : strs)
        {
            fill(count, count + 26, 0);
            for (char c : str)
                count[c - 'a']++;

            string key = "";
            for (int i = 0; i < 26; i++)
            {
                key += '#';
                key += to_string(count[i]);
            }

            anagram_map[key].push_back(str);
        }

        for (auto str_group : anagram_map)
            ans.push_back(str_group.second);

        return ans;
    }
};

/*
Counter: (Runtime, Memory) = (8.10%, 9.11%)
Sorting: (Runtime, Memory) = (33.31%, 31.03%)
모든 문자를 다 읽긴 해야 하므로 O(NK)보다 빠르게 풀 수는 없다.
counter를 써서 key를 만들면 O(K)에 키가 만들어지므로 O(NK),
sort를 쓰면 key 생성에 O(KlogK)가 걸리므로 O(NKlogK)가 된다.
다만 counter를 써서 키를 만드는게 일종의 hash function을 만드는
작업인지라 시간이 오래 걸리고, 최종적으론 sorting된 문자열을 키로
쓰는게 더 빠르게 동작한다. 문자열의 길이에 따라서 시간복잡도가 안
좋더라도 sort하는 풀이가 더 좋을 수 있음을 어필하면 좋을 것 같다.
공간복잡도는 둘 다 hash table을 사용하므로 O(N). sorting하는 풀이는
9행을 삭제하고 12~21행을 바꿔주면 된다.
*/