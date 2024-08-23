class Solution
{
public:
    int idx;

    int calculate(string s)
    {
        int result = 0;
        int operand = 0;
        int sign = 1;

        while (idx < s.length())
        {
            char c = s[idx++];
            if ('0' <= c && c <= '9')
            {
                operand = operand * 10 + (c - '0');
            }
            else if (c == '+')
            {
                result += sign * operand;
                sign = 1;
                operand = 0;
            }
            else if (c == '-')
            {
                result += sign * operand;
                sign = -1;
                operand = 0;
            }
            else if (c == '(')
            {
                operand = calculate(s);
            }
            else if (c == ')')
            {
                break;
            }
        }

        result += sign * operand;

        return result;
    }
};

/*
(Runtime, Memory) = (77.54%, 66.05%). #224 -> #227 -> #772 -> #770.
다행히도 *, /가 없어서 새로운 +/-가 올 때마다 바로바로 직전 계산 결과를
반영할 수 있다. 괄호가 열리면 이전 결과를 스택에 저장해놨다가 닫힌 괄호가
나올 때 괄호 안의 연산 결과를 스택에 저장해둔 것에 합친다. 시간, 공간 모두
O(N) 풀이. 괄호 안 부분을 재귀로 처리하는 다른 풀이도 확인.
*/