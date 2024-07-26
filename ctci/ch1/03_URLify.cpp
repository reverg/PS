#include <iostream>
#include <string>

using namespace std;

string urlify(string str)
{
    int num_of_spaces = 0;
    int len = str.length();
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] == ' ')
        {
            num_of_spaces++;
        }
    }

    int extended_len = str.length() + 2 * num_of_spaces;
    str.resize(extended_len, ' ');

    i = extended_len - 1;
    for (int j = len - 1; j >= 0; j--)
    {
        if (str[j] != ' ')
        {
            str[i--] = str[j];
        }
        else
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }
    return str;
}

int main()
{
    string str;
    getline(cin, str);
    cout << urlify(str);
}