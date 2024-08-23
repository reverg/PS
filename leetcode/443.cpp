class Solution
{
public:
    int compress(vector<char> &chars)
    {
        string compress_string;
        char prev_char = chars[0];
        int repeat_cnt = 1;

        for (int i = 1; i < chars.size(); i++)
        {
            if (prev_char == chars[i])
                repeat_cnt++;
            else
            {
                compress_string += prev_char;
                if (repeat_cnt >= 2)
                    compress_string += to_string(repeat_cnt);

                prev_char = chars[i];
                repeat_cnt = 1;
            }
        }
        compress_string += prev_char;
        if (repeat_cnt >= 2)
            compress_string += to_string(repeat_cnt);

        chars = vector<char>(compress_string.begin(), compress_string.end());
        return compress_string.size();
    }
};

/*
(Runtime, Memory) = (100.00%, 48.55%).
마지막에 string 1번 더 업데이트 해주는거 주의.
*/