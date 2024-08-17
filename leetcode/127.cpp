class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        queue<pair<string, int>> ladder_queue;
        ladder_queue.push({beginWord, 1});
        wordSet.erase(beginWord);

        while (!ladder_queue.empty())
        {
            string cur_word = ladder_queue.front().first;
            int cur_step = ladder_queue.front().second;
            ladder_queue.pop();

            if (cur_word == endWord)
                return cur_step;

            for (int i = 0; i < cur_word.size(); i++)
            {
                string nxt_word = cur_word;
                for (int j = 0; j < 26; j++)
                {
                    nxt_word[i] = 'a' + j;
                    if (wordSet.count(nxt_word))
                    {
                        ladder_queue.push({nxt_word, cur_step + 1});
                        wordSet.erase(nxt_word);
                    }
                }
            }
        }

        return 0;
    }
};

/*
(Runtime, Memory) = (94.85%, 44.02%)
BFS 문제. BFS를 써야겠다는 생각이 들면 시간제한을 걱정하면서 아래 내용을 확인해야 한다:
    단어의 길이(K), wordList 크기(N), 단어 구성하는 문자들(알파벳인지)
각 단어들이 유일한지는 굳이 신경 안 써도 된다. 어차피 set에 다 넣을거기 때문.
현재 단어에서 1글자씩을 바꿔보고 wordList에 존재하는 단어면 queue에 넣는다.
26개를 K개 위치에 대해 바꾸는걸 최대 N번 하므로 시간복잡도는 O(26KN),
공간복잡도는 set과 큐를 쓰는데 각 단어가 최대 1번씩 들어가므로 O(NK).
editorial은 substr을 써서 O(N^2 K)로 풀었던데 26행의 문자 1개 변경이 O(1)에 동작해서
굳이 그렇게 할 필요가 없다. 단어도 바꿀 수 있는걸 미리 저장해뒀는데 bfs에서 같은 단어를
2번 넣을 일이 없으므로 그냥 set에서 지워버리면 O(1)에 해결. 풀이 대충 쓰나보다.
*/