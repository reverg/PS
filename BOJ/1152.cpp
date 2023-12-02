#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    getline(cin,line);
    int space=0;

    for(int i=0; i<line.length(); i++)
    {
        if(line[i]==' ')
            space++;
    }

    int front=0, back=line.length()-1;
    while(line[front]==' ')
    {
        space--;
        front++;
    }
    while(line[back]==' ')
    {
        space--;
        back--;
    }

    cout<<space+1;

    return 0;
}