#include <iostream>
using namespace std;

int main()
{
    int c;
    int n;
    cin>>c;

    for(int i=0; i<c; i++)
    {
        cin>>n;
        int score[n];
        int sum=0;
        double average=0;
        int cnt=0;
        
        for(int j=0; j<n; j++)
        {
            cin>>score[j];
            sum+=score[j];
        }

        average=(double)sum/n;

        for(int j=0; j<n; j++)
        {
            if(average<score[j])
                cnt++;
        }

        cout.precision(3);
        cout<<fixed;
        cout<<(double)cnt/n*100<<"%"<<endl;
    }

    return 0;
}