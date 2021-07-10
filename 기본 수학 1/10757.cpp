#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int len = a.length() > b.length() ? a.length() : b.length();

    int aArr[len+1]={0, }, bArr[len+1]={0, };

    for (int i = 0; i < a.length(); i++)
    {
        aArr[i] = a[a.length() - i - 1]-'0';
    }

    for (int i = 0; i < b.length(); i++)
    {
        bArr[i] = b[b.length() - i - 1]-'0';
    }

    int res[len+1] = {
        0,
    };

    int c=0;

    for(int i=0; i<len+1; i++)
    {
        res[i]=(aArr[i]+bArr[i]+c)%10;
        c=(aArr[i]+bArr[i]+c)/10;
    }

    if(res[len]!=0)
        cout<<res[len];

    for(int i=1; i<len+1; i++)
    {
        cout<<res[len-i];
    }

    return 0;
}