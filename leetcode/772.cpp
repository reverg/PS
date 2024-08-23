class Solution
{
public:
    int idx = 0;

    int getOperand(string &s)
    {
        int operand = 0;
        while (idx < s.size())
        {
            if (isdigit(s[idx]))
            {
                operand = operand * 10 + (s[idx] - '0');
                idx++;
            }
            else
            {
                break;
            }
        }
        return operand;
    }

    int calculate(string s)
    {
        int result = 0;
        int operand = 0;
        int sign = 1;

        while (idx < s.size())
        {
            char c = s[idx];
            if (isdigit(c))
            {
                operand = getOperand(s);
            }
            else if (c == '+' || c == '-')
            {
                result += sign * operand;
                sign = (c == '+') ? 1 : -1;
                operand = 0;
                idx++;
            }
            else if (c == '*' || c == '/')
            {
                idx++;

                int next_operand;
                if (s[idx] == '(')
                {
                    idx++;
                    next_operand = calculate(s);
                }
                else
                    next_operand = getOperand(s);

                operand = (c == '*') ? (operand * next_operand)
                                     : (operand / next_operand);
            }
            else if (c == '(')
            {
                idx++;
                operand = calculate(s);
            }
            else if (c == ')')
            {
                idx++;
                break;
            }
        }

        result += sign * operand;

        return result;
    }
};

/*
(Runtime, Memory) = (100.00%, 16.80%). #224 -> #227 -> #772 -> #770.
스택으로 어떻게 풀어보려고 했는데 *,/ 때문에 너무 꼬인다. 그냥 재귀로 풂.
시간, 공간복잡도는 #224와 동일하게 O(N), O(N).
아래처럼 이전 연산들 잘 저장 + 스택으로 푸는 풀이도 있기는 하다.
근데 이거 C++로 짜긴 너무 빡셈...

class Solution:
    def calculate(self, s: str) -> int:
        def evaluate(x, y, operator):
            if operator == "+":
                return x
            if operator == "-":
                return -x
            if operator == "*":
                return x * y
            return int(x / y)

        stack = []
        curr = 0
        previous_operator = "+"
        s += "@"

        for c in s:
            if c.isdigit():
                curr = curr * 10 + int(c)
            elif c == "(":
                stack.append(previous_operator)
                previous_operator = "+"
            else:
                if previous_operator == "*" or previous_operator == "/":
                    stack.append(evaluate(stack.pop(), curr, previous_operator))
                else:
                    stack.append(evaluate(curr, 0, previous_operator))

                curr = 0
                previous_operator = c
                if c == ')':
                    while type(stack[-1]) == int:
                        curr += stack.pop()
                    previous_operator = stack.pop()

        return sum(stack)
*/