#include <iostream>
#include <array>

using namespace std;

void self_number_print(int arr[]);

int main()
{
    int chk_array[9999]={0, };
    self_number_print(chk_array);
    
    return 0;
}

void self_number_print(int arr[])
{
    int print_array[9999]={0, };

    for(int i=1; i<9999; i++)
    {
        int gen=i;
        int j=i;
        while(j!=0)
        {
            gen+=j%10;
            j/=10;
        }
        if(gen<9999)
            print_array[gen-1]++;
    }
    for(int i=0; i<9999; i++)
    {
        if(print_array[i]==0)
            cout<<i+1<<endl;
    }
}