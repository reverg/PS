#include <iostream>
using namespace std;

int main()
{
    char word[101]={0, };
    cin >> word;
    int alphabet[26];
    for(int i=0; i<26; i++)
        alphabet[i]=-1;

    for (int i = 99; i >= 0; i--)
    {
        if ('a' <= word[i] && word[i] <= 'z')
            alphabet[word[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " ";
    }

    return 0;
}