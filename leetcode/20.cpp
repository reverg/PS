class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> paran_stack;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                paran_stack.push(c);
            else
            {
                if (paran_stack.size() == 0)
                    return false;

                char corr_open;
                switch (c)
                {
                case ')':
                    corr_open = '(';
                    break;
                case '}':
                    corr_open = '{';
                    break;
                case ']':
                    corr_open = '[';
                    break;
                }

                if (paran_stack.top() != corr_open)
                    return false;
                else
                    paran_stack.pop();
            }
        }

        if (paran_stack.size() != 0)
            return false;
        else
            return true;
    }
};

/*
(Runtime, Memory) = (100.00%, 44.95%)
진짜 기초적인 stack 문제. 1분컷 해줘야 하는 문제다...
다만 예외 처리에 신경써줘야 한다. stack size가 0인 경우를 잊지 말 것.
*/