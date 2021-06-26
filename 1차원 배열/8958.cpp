#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        char answer[80];
        int total=0;
        int score=1;
        cin>>answer;

        for(int i=0; i<80; i++)
        {
             if(answer[i]=='O')
            {
                total+=score;
                score++;
            }
            else if(answer[i]=='X')
                score=1;
            else
            {
                cout<<total<<endl;
                break;
            }
        }
    }

}