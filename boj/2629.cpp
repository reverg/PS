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
    ios::sync_with_stdio(0);
    cin.tie(0);

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

/*
각각의 추에 대해 오른쪽에 올리기 / 왼쪽에 올리기 / 올리지 않기.
지금 코드는 따로 0 미만의 값을 없애지 않아 음수도 들어가지만,
어차피 왼쪽 오른쪽 뒤집으면 절대값은 같게 나와서 상관 없다.
*/