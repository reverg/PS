#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    getline(cin, word);
    int cnt = word.length();

    for (int i = 0; i < word.length() - 1; i++)
    {
        if (word[i + 1] == '=')
        {
            if (word[i] == 'c' || word[i] == 's' || word[i] == 'z')
                cnt--;
            if (i >= 1 && word[i] == 'z' && word[i - 1] == 'd')
                cnt--;
        }
        if (word[i + 1] == '-')
        {
            if (word[i] == 'c' || word[i] == 'd')
                cnt--;
        }
        if (word[i + 1] == 'j')
        {
            if (word[i] == 'l' || word[i] == 'n')
                cnt--;
        }
    }

    cout << cnt;

    return 0;
}