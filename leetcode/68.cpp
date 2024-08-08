class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> justified_texts;
        int cur_ptr = 0;

        while (cur_ptr < words.size())
        {
            int begin_ptr = cur_ptr;
            int cur_line_words_len = 0;
            cur_line_words_len += words[cur_ptr].length();
            cur_ptr++;

            while (cur_ptr < words.size() &&
                   (cur_line_words_len + (cur_ptr - begin_ptr)) +
                           words[cur_ptr].length() <=
                       maxWidth)
            {
                cur_line_words_len += words[cur_ptr].length();
                cur_ptr++;
            }

            string cur_line = "";
            int space_len = maxWidth - cur_line_words_len;

            if (cur_ptr == words.size())
            {
                for (int p = begin_ptr; p < cur_ptr - 1; p++)
                {
                    cur_line += words[p];
                    cur_line += " ";
                    space_len--;
                }
                cur_line += words[cur_ptr - 1];
                for (int i = 0; i < space_len; i++)
                    cur_line += " ";
            }
            else
            {
                if (begin_ptr + 1 == cur_ptr)
                {
                    cur_line += words[begin_ptr];
                    for (int i = 0; i < space_len; i++)
                        cur_line += " ";
                }
                else
                {
                    int unit_space = space_len / (cur_ptr - begin_ptr - 1);
                    int extra_space = space_len % (cur_ptr - begin_ptr - 1);

                    for (int p = begin_ptr; p < cur_ptr - 1; p++)
                    {
                        cur_line += words[p];
                        for (int i = 0; i < unit_space; i++)
                            cur_line += " ";
                        if (extra_space)
                        {
                            cur_line += " ";
                            extra_space--;
                        }
                    }
                    cur_line += words[cur_ptr - 1];
                }
            }

            justified_texts.push_back(cur_line);
        }

        return justified_texts;
    }
};

/*
(Runtime, Memory) = (10.88%, 24.39%)
word랑 띄어쓰기 구간이 max_length 안 넘을 때까지 잘 들고 온 다음에,
띄어쓰기를 얼마나 해야 할 지 계산해서 줄 단위로 만들어 저장했다.
발상이 어렵지는 않은데 아니 뭔 처리가... 단어 1번씩 보므로 O(N).
string의 length는 constant에 나온다. 속도랑 메모리 안 좋은건 사용한
방법이 별로 좋지 않아서 그런 것으로 추정. 공간은 (줄 수) * (줄 길이)만큼
쓸텐데 최대가 300*100이라 의미는 없다.
*/