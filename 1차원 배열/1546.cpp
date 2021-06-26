#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int max=0;
    int score[n];
    double modified_score[n];
    double modified_sum=0;

    for(int i=0; i<n; i++)
    {
        cin>>score[i];
        if(score[i]>max)
            max=score[i];
    }

    for(int i=0; i<n; i++)
    {
        modified_score[i]=(double)score[i]*100/max;
        modified_sum+=modified_score[i];
    }

    cout<<modified_sum/n;
    
    return 0;
}