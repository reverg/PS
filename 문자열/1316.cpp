#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n=0;
    int group_cnt=0;
    cin>>n;
    cin.get();
    
    for(int i=0; i<n; i++)
    {
        int alphabet[26]={0, };
        string word;
        getline(cin, word);
        int chk=1;
        
        for(int i=0; i<word.length(); i++)
        {
            if(alphabet[word[i]-'a']==0)
            {
                alphabet[word[i]-'a']=1;
            }
            else if(alphabet[word[i]-'a']==1)
            {
                if(word[i]!=word[i-1])
                    alphabet[word[i]-'a']=-1;
            }
        }

       for(int i=0; i<26; i++)
       {
            if(alphabet[i]==-1)
                chk=0;
       }

        if(chk==1)
            group_cnt++;    
    }

    cout<<group_cnt;
    
    return 0;
}