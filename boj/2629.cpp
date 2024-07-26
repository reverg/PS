#include <iostream>
#include <vector>
#include <set>

using namespace std;

int weight[31];
set<int> constructed;

void getWeight(int n)
{
    constructed.insert(0);
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        for (auto it : constructed)
        {
            tmp.push_back(it + weight[i]);
            tmp.push_back(it - weight[i]);
        }
        for (auto it : tmp)
            constructed.insert(it);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    getWeight(n);

    int k;
    cin >> k;

    int marble;
    for (int i = 1; i <= k; i++)
    {
        cin >> marble;
        if (constructed.count(marble))
            cout << "Y ";
        else
            cout << "N ";
    }
}