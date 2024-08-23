class Solution
{
public:
    int getOperand(string &s, int &i)
    {
        int operand = 0;
        while (i < s.size())
        {
            if (isdigit(s[i]))
            {
                operand = operand * 10 + (s[i] - '0');
                i++;
            }
            else
            {
                if (s[i] == ' ')
                    i++;
                else
                {
                    i--;
                    break;
                }
            }
        }
        return operand;
    }

    int calculate(string s)
    {
        int result = 0;
        int sign = 1;
        int operand = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
                operand = getOperand(s, i);
            else if (s[i] == '+' || s[i] == '-')
            {
                result += sign * operand;
                sign = (s[i] == '+') ? 1 : -1;
                operand = 0;
            }
            else if (s[i] == '*')
            {
                i++;
                int next_operand = getOperand(s, i);
                operand *= next_operand;
            }
            else if (s[i] == '/')
            {
                i++;
                int next_operand = getOperand(s, i);
                operand /= next_operand;
            }
        }

        result += sign * operand;

        return result;
    }
};

/*
(Runtime, Memory) = (96.50%, 95.10%). #224 -> #227 -> #772 -> #770.
*, /가 생기고 괄호가 없어진 문제. +/-는 #224와 동일하게 처리하면 되지만
곱하기와 나누기는 뒷 수를 알아야 처리할 수 있다. 다음 operand를 확인해서
현재 operand에 곱하기/나누기를 하면 된다. i를 getOperand에서 공유하게
만들어서 처리했는데 전역변수로 idx를 따로 두면 좀 더 편할 듯 하다.
시간복잡도는 O(N), 공간복잡도는 O(1)에 처리된다.

비슷한 느낌으로 직전 operand와 현재 operand 2개를 들고서 움직이는 방법도 있다.
시간/공간은 똑같은데 개인적으로는 현재 코드가 좀 더 편하다. 아래 코드 참고.

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int curOperand = 0;
        int lastOperand = 0;
        char sign = '+';

        for (int i = 0; i < s.size(); i++) {
            char curChar = s[i];
            if (isdigit(curChar))
                curOperand = (curOperand * 10) + (curChar - '0');
            if (!(isdigit(curChar) || iswspace(curChar)) || i == s.size() - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastOperand;
                    lastOperand = (sign == '+') ? curOperand : -curOperand;
                } else if (sign == '*') {
                    lastOperand *= curOperand;
                } else if (sign == '/') {
                    lastOperand /= curOperand;
                }
                sign = curChar;
                curOperand = 0;
            }
        }

        result += lastOperand;

        return result;
    }
};
*/