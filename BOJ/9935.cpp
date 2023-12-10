#include <iostream>
#include <stack>

using namespace std;

string str, explosive;

void input()
{
    cin >> str;
    cin >> explosive;
}

string explode()
{
    stack<char> st1;

    for (int i = 0; i < str.size(); i++)
    {
        st1.emplace(str[i]);
        if (str[i] == explosive[explosive.size() - 1])
        {
            int pos = explosive.size() - 1;
            stack<char> st2;

            while (st1.top() == explosive[pos])
            {
                st2.emplace(st1.top());
                st1.pop();
                pos--;

                if (pos < 0 || st1.empty())
                    break;
            }

            if (pos >= 0)
            {
                pos++;
                while (pos < explosive.size())
                {
                    st1.emplace(st2.top());
                    st2.pop();
                    pos++;
                }
            }
        }
    }

    string result(st1.size(), ' ');
    if (st1.empty())
    {
        result = "FRULA";
    }
    else
    {
        result.resize(st1.size());
        for (int i = st1.size() - 1; i >= 0; i--)
        {
            result[i] = st1.top();
            st1.pop();
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cout << explode() << endl;
}