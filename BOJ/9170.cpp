#include <iostream>
#include <string>

using namespace std;

string input;
int ptr;

int parseExpr();
int parseTerm();

int parseTerm()
{
    int out = 0;
    if (input[ptr] == '(')
    {
        ptr++;
        if (input[ptr] == '+')
        {
            ptr++;
            out = parseTerm();
        }
        else if (input[ptr] == '-')
        {
            ptr++;
            out = -parseTerm();
        }
        else
            out = parseExpr();

        if (input[ptr] == ')')
            ptr++;
    }
    else if ('0' <= input[ptr] && input[ptr] <= '9')
    {
        out = input[ptr] - '0';
        ptr++;
    }

    return out;
}

int parseExpr()
{
    int out = parseTerm();

    while (ptr < input.length())
    {
        if (input[ptr] == '+')
        {
            ptr++;
            out += parseTerm();
        }
        else if (input[ptr] == '-')
        {
            ptr++;
            out -= parseTerm();
        }
        else
            break;
    }

    return out;
}

int main()
{
    while (cin >> input){
        cout << parseExpr() << '\n';
        ptr = 0;
    }
        
}