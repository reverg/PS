#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    int alphabet[26] = {0, };
    int max=0;
    int cnt=0;

    getline(cin, word);

    for (int i = 0; i < word.length(); i++)
    {
        if ('a' <= word[i] && word[i] <= 'z')
            alphabet[word[i] - 'a']++;
        if ('A' <= word[i] && word[i] <= 'Z')
            alphabet[word[i] - 'A']++;
    }

    for(int i=0; i<26; i++)
    {
        if(max<alphabet[i])
            max=alphabet[i];
    }

    for(int i=0; i<26; i++)
    {
        if(max==alphabet[i])
            cnt++;
    }

    if(cnt==1)
    {
        for(int i=0; i<26; i++)
        {
            if(alphabet[i]==max)
                cout<<char('A'+i);
        }
    }
    else
        cout<<"?";

    return 0;
}