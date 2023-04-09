#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    std::string input;
    std::stack<char> operation;

    std::cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
        if ('A' <= input[i] && input[i] <= 'Z')
        {
            std::cout << input[i];
        }
        else
        {
            if (input[i] == '(')
            {
                operation.push(input[i]);
            }
            else if (input[i] == '*' || input[i] == '/')
            {
                while (!operation.empty() && (operation.top() == '*' || operation.top() == '/'))
                {
                    std::cout << operation.top();
                    operation.pop();
                }
                operation.push(input[i]);
            }
            else if (input[i] == '+' || input[i] == '-')
            {
                while (!operation.empty() && operation.top() != '(')
                {
                    std::cout << operation.top();
                    operation.pop();
                }
                operation.push(input[i]);
            }
            else if (input[i] == ')')
            {
                while (!operation.empty() && operation.top() != '(')
                {
                    std::cout << operation.top();
                    operation.pop();
                }
                operation.pop();
            }
        }
    }
    while (!operation.empty())
    {
        std::cout << operation.top();
        operation.pop();
    }
}