#include <iostream>
using namespace std;

int main()
{
    int notes[9] = {0, };
    int asc=0, des=0;

    for (int i = 0; i < 8; i++)
    {
        notes[i] = cin.get();
        cin.get();
    }

    
    for(int i=0; i<7; i++)
    {
        if(notes[i+1]>notes[i])
            asc++;
        else if(notes[i+1]<notes[i])
            des++;
    }

    if(asc==7)
        cout<<"ascending";
    else if(des==7)
        cout<<"descending";
    else
        cout<<"mixed";
}