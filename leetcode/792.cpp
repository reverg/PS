class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        queue<int> word_start_groups[26];
        int word_cur_pos[5000];
        fill(word_cur_pos, word_cur_pos + 5000, 0);

        for (int i = 0; i < words.size(); i++)
            word_start_groups[words[i][0] - 'a'].push(i);

        for (int i = 0; i < s.length(); i++)
        {
            int qs = word_start_groups[s[i] - 'a'].size();
            for (int j = 0; j < qs; j++)
            {
                int wid = word_start_groups[s[i] - 'a'].front();
                word_start_groups[s[i] - 'a'].pop();
                word_cur_pos[wid]++;
                if (word_cur_pos[wid] == words[wid].size())
                    continue;
                word_start_groups[words[wid][word_cur_pos[wid]] - 'a'].push(wid);
            }
        }

        int subseq_words_num = words.size();
        for (int i = 0; i < 26; i++)
            subseq_words_num -= word_start_groups[i].size();

        return subseq_words_num;
    }
};

/*
(Runtime, Memory) = (98.49%, 78.15%)
word 1개가 subsequence인지 확인할 때마다 s를 처음부터 끝까지 확인하면 O(NM)인데,
2억 5천만 정도라 TLE가 나온다. 포인터를 word 개수만큼 가지고 있으면서 s 1글자 읽고
포인터 조정하고를 반복하는 형식으로 하면 똑같이 O(NM)이긴 하지만 길이가 훨씬 긴 s를
읽는 횟수가 줄어들어 시간제한 안에 들어온다. queue 안에 string을 넣고 word.substr(1)
형식으로 계속 잘라내는 방식도 되지만, word를 매번 복사하므로 시간이 훨씬 오래 걸리기
때문에 int 값으로 position만 저장하도록 했다.
*/